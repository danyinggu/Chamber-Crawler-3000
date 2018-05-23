#include "game.h"
#include "controller.h"
#include "enemy.h"
#include "item.h"
#include "ba.h"
#include "bd.h"
#include "wa.h"
#include "wd.h"
#include "potion.h"
#include "gold.h"
#include "vampire.h"
#include "shade.h"
#include "drow.h"
#include "goblin.h"
#include "troll.h"
#include <ctime>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "dragon.h"
using namespace std;

Game::Game():floor(0),controller(NULL),
             player(NULL),theFloor(NULL),inputType('0'){
  hostile= false;
//cerr << "4" <<endl;
}

Game::~Game(){
  clearFloor();
  delete player;
  player = NULL;
//cerr<< "destructor" <<endl;
}

void Game::clearFloor() {
  for(int x = 0; x < 25; ++x){
     delete[] theFloor[x];
  } //for
  
  delete[] theFloor;
  theFloor = NULL;

}

bool Game::isHostile() { return hostile;}
void Game::setHostile() {hostile = true;}

void Game::findPotion(string direction) {
	int x = player->getX();
	int y = player->getY();
	int newX,newY;
	if(direction == "no") {
   	    newX = x - 1;
            newY = y;
  } else if (direction == "so") {
            newX = x + 1;
            newY = y;
  } else if (direction == "ea") {
   	    newX = x;
   	    newY = y + 1;
  } else if (direction == "we") {
    newX = x;
    newY = y - 1;
  } else if (direction == "nw") {
    newX = x - 1;
    newY = y - 1;
  } else if (direction == "se") {
    newX = x + 1;
    newY = y + 1;
  } else if (direction == "ne") {
    newX = x - 1;
    newY = y + 1;
  } else {
    newX = x + 1;
    newY = y - 1;
  } 
  if((newX < 0) || (newX > 24) || (newY < 0) || (newY > 78)) return;
  else if(theFloor[newX][newY].getRole() != 'P') return;
  else{
        string cmd = "PC uses "; 
	Potion* temp = theFloor[newX][newY].getPotion();
	temp->Apply(player);
	cmd += temp->getName();
	cmd +=".";
	controller->notifyAction(cmd);
	theFloor[newX][newY].setPotion();
	theFloor[newX][newY].setState('.');
	notify(newX, newY, '.');	
        controller->notifyPlayer(player->getHP(), player->getDef(),player->getAtk(),player->getGold());
  }
}
  

Player* Game::getPlayer() {
  return this->player;
}

void Game::setPlayer(Player* p) {
  this->player = p;
}

void Game::initMap(ifstream* input) {
  string mapLine;
  bool dragon = false;
  for(int x = 0; x < 25; ++x) {
    getline(*input,mapLine);
// cerr << mapLine << endl;
    for(int y = 0; y < 79; ++y) {
       char c;
      char orig;
      theFloor[x][y].setCoords(x,y);
      if((mapLine[y] >= '0') && (mapLine[y] <= '5')) {
        c = 'P';
        orig = '.';
        theFloor[x][y].setPotion(mapLine[y] - '0');

      } else if((mapLine[y] >= '6') && (mapLine[y] <= '9')) {
        c = 'G';
        orig = '.';
        if(mapLine[y] == '6') { theFloor[x][y].setGold('n');}
        else if (mapLine[y] == '7') { theFloor[x][y].setGold('s');}
        else if (mapLine[y] == '8') { theFloor[x][y].setGold('m');}
        else {theFloor[x][y].setGold('b');
               dragon = true;}
      } else if (mapLine[y] == '@') {
        c = '@';
        orig = '.';
        theFloor[x][y].setPlayer(this->player);  
        player->setCoords(x,y);
        controller->notifyAction("Player character has spawned.");
      } else if ((mapLine[y] == 'O')||(mapLine[y] == 'H')||(mapLine[y] == 'M')||
            (mapLine[y] == 'W')||(mapLine[y] == 'L')||(mapLine[y] == 'E')||(mapLine[y] == 'D')) {
        c = mapLine[y];
        orig = '.';
        theFloor[x][y].setEnemy(c);

      } else {
        c = mapLine[y];
        orig = c;
      }

      theFloor[x][y].setState(c);
      theFloor[x][y].setOrigState(orig);
      //theFloor[x][y].setCoords(x,y);
      notify(x,y,c);
    }

  }
  if(dragon == true) setDragon();
   return;

//  input->close();
///////////
/*for(int i = 0; i < 25; ++i) {
    for(int j = 0; j < 79; ++j) {
      cout<<theFloor[i][j].getRole();
    }
    cout << endl;
  }
*/
}
void Game::setDragon() {
  for(int x = 0; x < 25; ++x) {
    for(int y = 0; y < 79; ++y) {
      if(theFloor[x][y].getRole() == 'D') {
//cerr << "8" <<endl;
//cerr << "DragonX:" <<x <<"DragonY:"<< y<<endl;
        string allDirections[8] = { "no", "so", "ea", "we", "ne", "nw", "se", "sw"};
        string nextDirection;
        if((theFloor[x+1][y].getRole() == 'G') && (theFloor[x+1][y].getGold()->checkValid() == false) &&
           (theFloor[x+1][y].getGold()->isSeted() == false)) {
        //  theFloor[x+1][y].getGold()->setDragon(theFloor[x][y].enemy);
          theFloor[x][y].getEnemy()->setGold(theFloor[x+1][y].getGold());
          theFloor[x+1][y].getGold()->set();
        } else if ((theFloor[x-1][y].getRole() == 'G') && (theFloor[x-1][y].getGold()->checkValid() == false) &&
           (theFloor[x-1][y].getGold()->isSeted() == false)) {
//cerr << "9"<<endl;
         // theFloor[x-1][y].getGold()->setDragon(theFloor[x][y].enemy);
          theFloor[x][y].getEnemy()->setGold(theFloor[x-1][y].getGold());
//cerr<<"10"<<endl;
          theFloor[x-1][y].getGold()->set();
        } else if ((theFloor[x][y+1].getRole() == 'G') && (theFloor[x][y+1].getGold()->checkValid() == false) &&
           (theFloor[x][y+1].getGold()->isSeted() == false)) {
        //  theFloor[x][y+1].getGold()->setDragon(theFloor[x][y].enemy);
          theFloor[x][y].getEnemy()->setGold(theFloor[x][y+1].getGold());
          theFloor[x][y+1].getGold()->set();
        } else if ((theFloor[x][y-1].getRole() == 'G') && (theFloor[x][y-1].getGold()->checkValid() == false) &&
           (theFloor[x][y-1].getGold()->isSeted() == false)) {
        //  theFloor[x][y-1].getGold()->setDragon(theFloor[x][y].enemy);
          theFloor[x][y].getEnemy()->setGold(theFloor[x][y-1].getGold());
          theFloor[x][y-1].getGold()->set();
        } else if ((theFloor[x+1][y+1].getRole() == 'G') && (theFloor[x+1][y+1].getGold()->checkValid() == false) &&
           (theFloor[x+1][y+1].getGold()->isSeted() == false)) {
         // theFloor[x+1][y+1].getGold()->setDragon(theFloor[x][y].enemy);
          theFloor[x][y].getEnemy()->setGold(theFloor[x+1][y+1].getGold());
          theFloor[x+1][y+1].getGold()->set();
        } else if ((theFloor[x+1][y-1].getRole() == 'G') && (theFloor[x+1][y-1].getGold()->checkValid() == false) &&
           (theFloor[x+1][y-1].getGold()->isSeted() == false)) {
         // theFloor[x+1][y-1].getGold()->setDragon(theFloor[x][y].enemy);
          theFloor[x][y].getEnemy()->setGold(theFloor[x+1][y-1].getGold());
          theFloor[x+1][y-1].getGold()->set();
        } else if ((theFloor[x-1][y-1].getRole() == 'G') && (theFloor[x-1][y-1].getGold()->checkValid() == false) &&
           (theFloor[x-1][y-1].getGold()->isSeted() == false)) {
         // theFloor[x-1][y-1].getGold()->setDragon(theFloor[x][y].enemy);
          theFloor[x][y].getEnemy()->setGold(theFloor[x-1][y-1].getGold());
          theFloor[x-1][y-1].getGold()->set();
        } else if ((theFloor[x-1][y+1].getRole() == 'G') && (theFloor[x-1][y+1].getGold()->checkValid() == false) &&
           (theFloor[x-1][y+1].getGold()->isSeted() == false)) {
         // theFloor[x-1][y+1].getGold()->setDragon(theFloor[x][y].enemy);
          theFloor[x][y].getEnemy()->setGold(theFloor[x-1][y+1].getGold());
          theFloor[x-1][y+1].getGold()->set();
        } else{}
      }
    }
  }
}


void Game::selectRoom(char role) {
  int num = rand() % 5 + 1;
  if((role == 92) && (player->getRoom() == num)) {
    selectRoom(role);
    return;
  }
////
//cerr<<"???"<<endl;
  initRoom(num, role);
//cerr<<"chulaia"<<endl;
}

void Game::initRoom(int roomNum, char role) {
  const int sizeRoom1 = 104;
  const int sizeRoom2 = 147;
  const int sizeRoom3 = 36;
  const int sizeRoom4 = 201;
  const int sizeRoom5 = 150;
  
  int newX = 0;
  int newY = 0;

  if(roomNum == 1) {
    const int rowNum = 26;
    const int colNum = 4;
    int num = rand() % sizeRoom1;
    newX = 3 + (num / rowNum);
    newY = 3 + (num % rowNum);
  } else if (roomNum == 2) {
    const int rowNum = 21;
    const int colNum = 7;
    int num = rand() % sizeRoom2;

    newX = 15 + (num / rowNum);
    newY = 4 + (num % rowNum);
  } else if (roomNum == 3) {
    const int rowNum = 12;
    const int colNum = 3;
    int num = rand() % sizeRoom3;
    newX = 10 + (num / rowNum);
    newY = 38 + (num % rowNum);
    
  } else if (roomNum == 4) {
    int num = rand() % sizeRoom4;
    if((num >= 0) && (num <= 45)) {
      newX = 3 + (num / 23);
      newY = 39 + (num % 23);
    } else if ((num >= 46) && (num <= 76)) {
      newX = 5;
      newY = 39 + (num - 46);
    } else if ((num >= 77) && (num <= 110)) {
      newX = 6;
      newY = 39 + (num - 77);
    } else {
      int newNum = num - 111;
      newX = 7 + (newNum / 15);
      newY = 61 + (newNum % 15);
   }
  } else {
    int num = rand() % sizeRoom5;
    if((num >= 0) && (num <= 32)) {
      newX = 16 + (num / 11);
      newY = 65 + (num % 11);
    } else {
      int newNum = num - 33;
      newX = 19 + (newNum / 39);
      newY = 37 + (newNum % 39);
    }
  }

  if(theFloor[newX][newY].getRole() != '.') {
   
      selectRoom(role);
      return;

  } else  {
     
      if((role == 'b') && (!((theFloor[newX][newY-1].getRole() == '.') || (theFloor[newX-1][newY].getRole() == '.') ||
         (theFloor[newX][newY+1].getRole() == '.') || (theFloor[newX+1][newY].getRole() == '.') ||
         (theFloor[newX+1][newY+1].getRole() == '.') || (theFloor[newX-1][newY-1].getRole() == '.') ||
         (theFloor[newX][newY+1].getRole() == '.') || (theFloor[newX+1][newY].getRole() == '.')))) { 
      selectRoom(role);
      return;
      }
//dragon
      if((role == 's') ||(role=='b')||(role=='n')) {
        theFloor[newX][newY].setState('G');
        theFloor[newX][newY].setGold(role);
        if(role=='b')       { setDragon(newX, newY);}

        notify(newX, newY, 'G');
        return;
      }

      theFloor[newX][newY].setState(role);
//cerr<< "NEW X:" <<" " << newX<< endl;
//cerr<< "NEW Y:" <<" " << newY<< endl;

//cerr<<"Player X: " << player->getX() << "Y: " << player->getY() <<endl;

//cerr<<"9"<<endl;
      notify(newX, newY, role);
//cerr<<"10"<<endl; 
      if(role == '@') {
        player->setCoords(newX,newY);
        player->setRoom(roomNum);
        theFloor[newX][newY].setPlayer(this->player);
        controller->notifyAction("Player character has spawned.");
      } else if (role == 'P') {
        int p = rand() % 6;
        theFloor[newX][newY].setPotion(p);
      } else if ((role=='H')||(role=='W')||(role=='E')||(role=='O')
                 ||(role=='M')|| (role=='L')) {
        theFloor[newX][newY].setEnemy(role);
      } else {}


  } 
  
}

    
//void Game::setInput(ifstream* in) {
  //ifstream in(fileName.c_str());
//  input = in;
//}

int eNum = 0;

/*void Game::initEnemy() {
  for(int i = 0; i < 20; ++i) {
    initE();
  }
}

void Game::initE() {
      int num = rand();
cerr << "NUMRANDOM" << num <<endl;
      int e = num % 18 + 1;
cerr<<"eeeeeeee" <<e <<endl;
      if((1 <= e) && (e <= 4)) {
        selectRoom('H');
      } else if ((5<=e)&&(e<=7)) {
         selectRoom('W');
      } else if ((8<=e)&&(e<=12)) {
         selectRoom('L');
      } else if ((e == 13) || (e == 14)) {
cerr<<"EEEE: " <<e << endl;
         if(eNum >=4) {
           initE();
           return;
         } else {
           selectRoom('E');
           eNum++;
         }
      } else if ((e==15) || (e ==16)) {
         selectRoom('O');
      } else {
         selectRoom('M');
      }
}
*/

void Game::init(Controller *controller, char inputType, ifstream* input) {
  if(theFloor == NULL ) {
    this->controller = controller;
    this->inputType = inputType;
  }
controller->notifyPlayer(player->getHP(),player->getDef(),
                           player->getAtk(),player->getGold());
//cerr << "2" <<endl;
  if(theFloor != NULL) clearFloor();
//cerr << "3" << endl;
//cerr << "4" <<endl;
//////  
  ++floor;


  theFloor = new Cell*[25];
  for(int x = 0; x < 25; ++x) {
    theFloor[x] = new Cell[79];
    for(int y = 0; y < 79; ++y) {
      theFloor[x][y].setGame(this);
    } //for
  }
//cerr << "5" <<endl;
  initMap(input);
  controller->getTD()->print(cout);
//cerr<< "4" << endl;
  if(inputType == 'd') {
 //   srand(unsigned(time(NULL)));
//cerr<<"7"<<endl;
    selectRoom('@');
//cerr<<"8"<<endl;
    selectRoom(92);

    for(int i = 0; i < 10; ++i) {
      selectRoom('P');
    }

    for(int i = 0; i < 10; ++i) {
      int g = rand() % 8 + 1;
      if((g>=1) && (g<=5)) {
        selectRoom('n');
      } else if (g == 6) {
        selectRoom('b');            //dragon hoard
      } else {
        selectRoom('s');
      }
    }
//    eNum = 0;
//    initEnemy();
    for(int i = 0; i < 20; ++i) {
//cerr << "NUMRANDOM" << num <<endl;
      int e = rand() % 18 + 1;
//cerr<<"eeeeeeee" <<e <<endl;
      if((1 <= e) && (e <= 4)) {
        selectRoom('H');
      } else if ((5<=e)&&(e<=7)) {
         selectRoom('W');
      } else if ((8<=e)&&(e<=12)) {
         selectRoom('L');
      } else if ((e == 13) || (e == 14)) {
//cerr<<"EEEE: " <<e << endl;
         selectRoom('E');
      } else if ((e==15) || (e ==16)) {
         selectRoom('O');
      } else {
         selectRoom('M');
      }
    } 
  } // if inputType is default

}


void Game::notify(int x, int y, char role) {
  controller->notify(x,y,role);
}

void Game::createPlayer(string race) {
   if(race == "d") player = new Drow();
   else if (race == "v") player = new Vampire();
  else if (race == "t") player = new Troll();
  else if (race == "g") player = new Goblin(); 
  else{ 
  player = new Shade();
  }
}

void Game::setDragon(int x, int y) {
    string allDirections[8] = { "no", "so", "ea", "we", "ne", "nw", "se", "sw"};
    string nextDirection;
    int newX, newY;
    while(1) {
        int num = rand() % 8;
        nextDirection = allDirections[num];
        if(nextDirection == "no") {
             newX = x - 1;
             newY = y;
        }
        else if(nextDirection == "so") {
             newX = x + 1;
             newY = y;
        }
        else if(nextDirection == "ea") {
             newX = x;
             newY = y + 1;
        }
        else if(nextDirection == "we") {
             newX = x;
             newY = y - 1;
        }
        else if(nextDirection == "nw") {
             newX = x - 1;
             newY = y - 1;
        }
        else if(nextDirection == "se") {
             newX = x + 1;
             newY = y + 1;
        }
        else if(nextDirection == "ne") {
             newX = x - 1;
             newY = y + 1;
        } else {
             newX = x + 1;
             newY = y - 1;
       }
    if((newX < 0) || (newX > 24) || (newY < 0) || (newY > 78)) continue;
    if(theFloor[newX][newY].getRole()!='.') continue;
    Dragon * g = new Dragon(newX,newY,theFloor[x][y].getGold());
    theFloor[newX][newY].setEn(g);
    theFloor[newX][newY].setState('D');
    notify(newX,newY,'D');
       break;
    }
}


void Game::movePlayer(string cmd) {
  int x = player->getX();
  int y = player->getY();
//cerr<<"Current position X: " << x << "Y: " <<y<<endl;
  int newX,newY;
  if(cmd == "no") {
    newX = x - 1;
    newY = y;
   // if(newX < 0) return;
  } else if (cmd == "so") {
    newX = x + 1;
    newY = y;
   // if(newX > 24) return;
  } else if (cmd == "ea") {
    newX = x;
    newY = y + 1;
   // if(newY > 78) return;
  } else if (cmd == "we") {
    newX = x;
    newY = y - 1;
   // if(newY < 0) return;
  } else if (cmd == "nw") {
    newX = x - 1;
    newY = y - 1;
  } else if (cmd == "se") {
    newX = x + 1;
    newY = y + 1;
  } else if (cmd == "ne") {
    newX = x - 1;
    newY = y + 1;
  } else {
    newX = x + 1;
    newY = y - 1;
  }
//cerr<<"New position newX: " << newX << " newY: " << newY <<endl;  
  if((newX < 0) || (newX > 24) || (newY < 0) || (newY > 78)) return;

//cerr<<"11" <<endl;

  if(theFloor[newX][newY].getRole() == 92) {
    controller->setUp();
    return;
  }
  /*
  if(theFloor[newX][newY].getRole() == 'G') {
       if(theFloor[newX][newY].getGold()->checkValid() == false) return;
  }*/

  if((theFloor[newX][newY].getRole() == '.') ||
     (theFloor[newX][newY].getRole() == '#') ||
     (theFloor[newX][newY].getRole() == '+') ||
     (theFloor[newX][newY].getRole() =='G')){
//cerr<<"13"<<endl;
    if(cmd == "no") {          controller->notifyAction("Player moves North.");
  } else if (cmd == "so") {    controller->notifyAction("Player moves South.");
  } else if (cmd == "ea") {    controller->notifyAction("Player moves East.");
  } else if (cmd == "we") {    controller->notifyAction("Player moves West.");
  } else if (cmd == "nw") {    controller->notifyAction("Player moves NorthWest.");
  } else if (cmd == "se") {    controller->notifyAction("Player moves SouthEast.");
  } else if (cmd == "ne") {    controller->notifyAction("Player moves Northeast.");
  } else {                     controller->notifyAction("Player moves SouthWest."); }
// cerr<< "qingwen get chu le sha a :"<<theFloor[newX][newY].getRole()<<endl;
// not gold
//cerr<<"14"<<endl;
    if(theFloor[newX][newY].getRole() == 'G') {
      if(theFloor[newX][newY].getGold()->checkValid() == false) {
        controller->notifyAction("Player walks over a dragon hoard protected by dragon.");
      } else {
//cerr<<player->getGold() <<endl;
        this->player->useItem(theFloor[newX][newY].getGold());
//cerr<<player->getGold() <<endl;
        theFloor[newX][newY].setGold();
        controller->notifyAction("Player picks up a gold.");
       }
     }

//cerr<<"13"<<endl;
// cerr<< "qingwen get chu le sha a :"<<theFloor[newX][newY].getRole()<<endl;
// not gold
//cerr<<"14"<<endl;

    theFloor[newX][newY].setPlayer(this->player);
//cerr<<"nihao"<<endl;
    theFloor[newX][newY].setState('@');
//cerr<<"xiexie"<<endl;
    notify(newX, newY, '@');
//cerr<<"xienimabi"<<endl;
    theFloor[x][y].setPlayer(NULL);
//cerr<<"wotamajiuxie"<<endl;
    char origState = theFloor[x][y].getOrigState();
//cerr<<"nimasile"<<endl;
     if((theFloor[x][y].getGold() != NULL) && (theFloor[x][y].getGold()->checkValid())) {
       this->player->useItem(theFloor[x][y].getGold());
//cerr<<"WWWWWWWWWW"  <<endl;
       theFloor[x][y].setGold();
       controller->notifyAction("Player kills a dragon and immediately pick up dragon hoard.");
       theFloor[x][y].setState(origState);
       notify(x,y,origState);}
    else if (theFloor[x][y].getGold()!= NULL) {theFloor[x][y].setState('G');
                  				notify(x,y,'G');}
    else {theFloor[x][y].setState(origState);
          notify(x,y,origState);}

//cerr<<"bumeisi"<<endl;
    
//cerr<<"hehe"<<endl;



  player->move(newX, newY);
   controller->notifyPlayer(player->getHP(),player->getDef(), player->getAtk(),player->getGold());
//cerr<<"shizhelima?"<<endl;
// print delete when formal
/*
  for(int i = 0; i < 25; ++i) {
    for(int j = 0; j < 79; ++j) {
      cout<<theFloor[i][j].getRole();
    }
    cout << endl;
  }
*/
  }

}



void Game::attack(string direction){
	int x = player->getX();
        int y = player->getY();
	int newX, newY;
	if(direction == "no") {
		newX = x - 1;
		newY = y;
	}
	else if(direction == "so") {
		newX = x + 1;
		newY = y;
	}
	else if(direction == "ea") {
		newX = x;
		newY = y + 1;
	}
	else if(direction == "we") { 
		newX = x;
		newY = y - 1;
	}
	else if(direction == "nw") {
		newX = x - 1;
		newY = y - 1;
	}
	else if(direction == "se") {
		newX = x + 1;
		newY = y + 1;
	}
	else if(direction == "ne") {
		newX = x - 1;
		newY = y + 1;
	}
	else {
		newX = x + 1;
		newY = y - 1;
	}
	if((newX < 0) || (newX > 24) || (newY < 0) || (newY > 78)) return;
	
	Enemy* e = theFloor[newX][newY].getEnemy();
        int prevHP;
	if(e == NULL) return;
        else{
        prevHP = e->getHP();
	player->attack(e);
	}
        char eName = theFloor[newX][newY].getRole();
        ostringstream name;
        name << eName;
        int currHP = e->getHP();
	//cout << e->HP << endl;
	if(e->getHP() <= 0) {
          if('D' == theFloor[newX][newY].getRole()) {
                    theFloor[newX][newY].getEnemy()->getGold()->setValid();
           } else{

		e->sendGolds(player);
		if(eName == 'M') hostile = true;
            }
		theFloor[newX][newY].setEnemy();
		theFloor[newX][newY].setState('.');
		notify(newX, newY, '.');
          
	}
    
        int hp = abs(currHP - prevHP);
        ostringstream changeHP;
        changeHP << hp;
        ostringstream cHP;
        cHP << currHP;
        string cmd = "";
        cmd += "PC deals ";
        cmd += changeHP.str();
        cmd += " damage to ";
        cmd += name.str();
        cmd += " (";
        cmd += cHP.str();
        cmd += " HP).";
        controller->notifyAction(cmd);
        controller->notifyPlayer(player->getHP(),player->getDef(),player->getAtk(),player->getGold());
	
}

void Game::enemyAction(){
	string allDirections[8] = { "no", "so", "ea", "we", "ne", "nw", "se", "sw"};
	string nextDirection;
	int newX, newY;
	bool attacked = false;
	for(int x = 0; x < 25; ++x) {
    		for(int y = 0; y < 79; ++y) {
			attacked = false;
      			Enemy* en = theFloor[x][y].getEnemy();
			 if((en != NULL) && (theFloor[x][y].getRole() != 'D')) {
				if(en->updated) continue;
				for(int i=0;i<8;i++){
					nextDirection = allDirections[i];
					if(nextDirection == "no") {
                                              newX = x - 1;
              				      newY = y;
       					 }
     				        else if(nextDirection == "so") {
              				      newX = x + 1;
              				      newY = y;
       					 }
     				        else if(nextDirection == "ea") {
              			        newX = x;
              			        newY = y + 1;
       				        }
      				        else if(nextDirection == "we") {
             			        newX = x;
            			        newY = y - 1;
       				        }
       				        else if(nextDirection == "nw") {
            			        newX = x - 1;
              			        newY = y - 1;
       				        }
     				        else if(nextDirection == "se") {
             			        newX = x + 1;
            			        newY = y + 1;
      				        }
      			                else if(nextDirection == "ne") {
            				newX = x - 1;
              			        newY = y + 1;
      				        }
      				        else {
             			        newX = x + 1;
               			        newY = y - 1;
      					}
       					if((newX < 0) || (newX > 24) || (newY < 0) || (newY > 78)) continue;
					else if(theFloor[newX][newY].getPlayer() != NULL) {
						if(en->getHostile()||((!en->getHostile())&&hostile)) {
                                   			int prevHP = player->getHP();
							en->attack(player);
							int currHP = player->getHP();
             						int changeHP = abs(prevHP - currHP);
//	cout << prevHP << " " << currHP << " " << changeHP << endl;
							if(changeHP > 0) {
							 char eName=theFloor[x][y].getRole();
						         ostringstream name;
							 name << eName;
							 ostringstream cHP;
							 cHP << changeHP;
							 string cmd = name.str();
 							 cmd+=" deals ";
							 cmd+=cHP.str();
							 cmd+=" to PC.";
						//	cout << name << endl;
						   	 controller->notifyAction(cmd);
							}
							attacked = true;
							en->updated = true;
							break;
						}
					}
		             }
			if(!attacked){
                                while(1) {
			        	int num = rand() % 8;
				        nextDirection = allDirections[num];
					if(nextDirection == "no") {
                                              newX = x - 1;
                                              newY = y;
                                         }
                                        else if(nextDirection == "so") {
                                              newX = x + 1;
                                              newY = y;
                                         }
                                        else if(nextDirection == "ea") {
                                        newX = x;
                                        newY = y + 1;
                                        }
                                        else if(nextDirection == "we") {
                                        newX = x;
                                        newY = y - 1;
                                        }
                                        else if(nextDirection == "nw") {
                                        newX = x - 1;
                                        newY = y - 1;
                                        }
                                        else if(nextDirection == "se") {
                                        newX = x + 1;
                                        newY = y + 1;
                                        }
                                        else if(nextDirection == "ne") {
                                        newX = x - 1;
                                        newY = y + 1;
                                        }
                                        else {
                                        newX = x + 1;
                                        newY = y - 1;
                                        }
                                        if((newX < 0) || (newX > 24) || (newY < 0) || (newY > 78)) continue; 
				        if(theFloor[newX][newY].getRole()!='.') continue;
                                        en->setCoords(newX,newY);
                                        theFloor[newX][newY].setState(theFloor[x][y].getRole());
                                        theFloor[x][y].setState('.');
                                        theFloor[newX][newY].setEn(en);
                                        theFloor[x][y].setEn(NULL);
                                        notify(x,y,'.');
                                        notify(newX,newY,theFloor[newX][newY].getRole());
					en->updated = true;
					break;
                                }
                      }
                   }
                   if(theFloor[x][y].getRole() == 'D') {
                     int px= player->getX();

//cerr << "X " << x << "Y " << y << endl;
                     int py = player->getY();
//cerr<< "PlayerX " << px << "   PlayerY " << py<< endl;
                     int dhX = theFloor[x][y].getEnemy()->getGold()->getX();
                     int dhY = theFloor[x][y].getEnemy()->getGold()->getY();
//cerr<< "hoardX :" <<dhX << "hoardY: " << dhY << endl;
                     if(((px == x-1) && (py == y))|| ((px == x+1) && (py == y)) ||
                        ((px == x) && (py == y-1))|| ((px == x) && (py == y+1)) ||
                        ((px == x-1) && (py == y-1))|| ((px == x+1) && (py == y-1)) ||
			((px == x-1) && (py == y+1))|| ((px == x+1) && (py == y+1)) ||
			((px == dhX-1) && (py == dhY))|| ((px == dhX+1) && (py == dhY)) ||
			((px == dhX) && (py == dhY-1))|| ((px == dhX) && (py == dhY+1)) ||
                        ((px == dhX-1) && (py == dhY-1))|| ((px == dhX+1) && (py == dhY-1)) ||
                        ((px == dhX-1) && (py == dhY+1))|| ((px == dhX+1) && (py == dhY+1)) ||
                        ((px == dhX) && (py == dhY))) {
                        
                         int prevHP = player->getHP();
                         en->attack(player);
                         int currHP = player->getHP();
                         int changeHP = abs(prevHP - currHP);
                         if(changeHP > 0) {
                           char eName=theFloor[x][y].getRole();
                           ostringstream name;
                           name << eName;
                           ostringstream cHP;
                           cHP << changeHP;
                           string cmd = name.str();
                           cmd+=" deals ";
                           cmd+=cHP.str();
                           cmd+=" to PC.";
                           controller->notifyAction(cmd);
                        }
                    }
                  } 
		}
		}

	for(int x = 0; x < 25; ++x) {
          for(int y = 0; y < 79; ++y) {
            if(theFloor[x][y].getEnemy()!=NULL) theFloor[x][y].getEnemy()->updated = false;
	    }
          }

       // controller->notifyPlayer(player->getHP(),player->getDef(),player->getAtk(),player->getGold());

        controller->notifyPlayer(player->getHP(),player->getDef(),player->getAtk(),player->getGold());

}





















