#include "controller.h"
#include "game.h"
//#include "textdisplay.h"
#include <ctime>
#include <iostream>

#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

Controller::Controller():fileName(""),floorNum(1), isUp(false){
  game = new Game();
  td = new TextDisplay();
}

Controller::~Controller() {
    delete game;
    delete td;
}
 
TextDisplay* Controller::getTD() {
  return td;
}

//bool Controller::isHostile() {return hostile;}

void Controller::play(string inFile){
  srand(unsigned(time(NULL)));
//    srand(GetCurrentProcessId());
  fileName = inFile;

 // specify a race player want to play,only when start new game or restart(no upstairs)
   string race;
cout << "Enter the type of race you want!" << endl;
   while(cin >> race) {
     if((race == "s") || (race == "d") || (race == "v") || (race == "g")
         || (race == "t")) {
     game->createPlayer(race);
     istringstream str(race);
     char r;
     str >> r;
     td->setRace(r);
     break;
     } //if
  // cout << "Enter the type of race you want!" << endl;
   } //while

  if(fileName == "")     fileName = "defaultMap.txt";
  ifstream in(fileName.c_str());
 // game->setInput(&in);

//cerr<<"1"<<endl;

  if(fileName == "defaultMap.txt") {
    game->init(this,'d', &in);           // initialize the game
  } else {
     game->init(this,'s', &in);          // initialize the game
  } //if, else
 
  td->setFloor(floorNum);               //set the first floor
 //td;??????????????????????????????????
 //delete td;
 // td = new TextDisplay();  

  td->print(cout);
 //  while(floorNum <= 5) {
//	cout<<"HEIHEIHEI!!! " << game->player->getY() << endl;
     string cmd;
     while(cin >> cmd) {
     if ((cmd == "no") || (cmd == "so") || (cmd == "ea") || (cmd == "we") ||
         (cmd == "nw") || (cmd == "se") || (cmd == "ne") || (cmd == "sw")) {
        game->movePlayer(cmd);
	if(isUp){
		while(game->getPlayer()->getComp() != NULL){
//		cerr << "hello?" << endl;
			Player* temp = game->getPlayer();
			game->setPlayer(game->getPlayer()->getComp());
			delete temp;
			temp = NULL;
		}
	notifyPlayer(game->getPlayer()->getHP(), game->getPlayer()->getDef(),game->getPlayer()->getAtk(),game->getPlayer()->getGold());
	}
        if((isUp) && (floorNum == 5)) {
	   cout << "You win!!!"<<endl;
	   cout << "Your score is: "<< game->getPlayer()->getGold()<<endl;
           cout << "Press r to restart the game or other character to quit!" << endl;
           string command;
           cin >> command;
           if(command == "r") {
               restart();
               break;
           } else { }
           break;
        } else if (isUp == true) {
///////////////////set a new floor???????
         isUp = false;
//cerr << "16" <<endl;
         floorNum++;
//         td->clearDisplay();
         td->setFloor(floorNum);
//	string temp;
//	getline(in, temp);

         if(fileName == "defaultMap.txt") {
            game->init(this,'d', &in);          // initialize the game
         } else {
            game->init(this,'s', &in);          // initialize the game

         }  //if, else
         td->print(cout);
         continue;
       } else {
     //    td->print(cout);
       } 

     } 

      else if (cmd == "u") {
        string dir;
        if((cin >> dir) && ((dir == "no") || (dir == "so") || (dir == "ea")
                            || (dir == "we") ||  (dir == "nw") || (dir == "se")
                            || (dir == "ne") || (dir == "sw"))) {
           game->findPotion(dir);
        }
      }

      else if (cmd == "a") {
        string dir;
        if((cin >> dir) && ((dir == "no") || (dir == "so") || (dir == "ea")
                          || (dir == "we") ||  (dir == "nw") || (dir == "se")
                          || (dir == "ne") || (dir == "sw"))) {
        game->attack(dir);
//	td->print(cout);
        }
     } 
       else if (cmd == "r") {
          restart();
	  break;
       } else if (cmd == "q") {
	  cout << "Thanks for admitting defeat. Have a nice day!"<<endl;
          break;
       }
          else {
         //  continue;
       }
       game->enemyAction();
	td->print(cout);
	if(td->getHP() <= 0) {
		cout << "You lose!" << endl;
		cout << "Your score is : " << td->getGold() << endl;
		cout << "Press r to restart the game or other character to quit!" << endl;
         	string com;
                cin >> com;
                if(com == "r") {
             	    restart();
                    break;
         	} else { }
          	break;
	}
    }
   return;
 // }
}



/*int Controller::getFloor() {
  return floorNum;
}
*/


void Controller::restart() {
    floorNum = 1;
    isUp = false;
    delete game;
    delete td;
    game = new Game();
    td = new TextDisplay();
    play(fileName);
 // how to specify a new floor

}

void Controller::setUp() {
  if(isUp == false) isUp = true;
}

void Controller::notify(int x, int y, char role) {
  td->notify(x,y,role);
}


/*void Controller::setGame(Game * game) {
  this->game = game;

}
*/

void Controller::notifyAction(string ac) {
  td->setAction(ac);
}

void Controller::notifyPlayer(int hp, int def, int atk, int g) {
    td->setVal(hp,def,atk,g);
}

