#include "textdisplay.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//constructor

TextDisplay::TextDisplay():floor(0),race('0'),Atk(0),Def(0),HP(0),
action(""),gold(0),hasPrinted(false) {
  const char defaultVal = '0';
  theDisplay = new char*[25];
  for(int x = 0; x < 25; x++) {
    theDisplay[x] = new char[79];
    for(int y = 0; y < 79; ++y) {
      theDisplay[x][y] = defaultVal;
    }
  }
}


TextDisplay::~TextDisplay() {
  clearDisplay();
}


void TextDisplay::clearDisplay() {
   for(int x = 0; x < 25; x++) {
    delete[] theDisplay[x];
  }
  delete[] theDisplay;
  theDisplay == NULL;
}

void TextDisplay::notify(int x, int y, char state) {
  theDisplay[x][y] = state;
}

void TextDisplay::setRace(char r) {
  this->race = r;
}

void TextDisplay::setVal(int hp, int def, int atk, int g) {
  this->gold = g;
  this->HP = hp;
  this->Atk = atk;
  this->Def = def;
}

void TextDisplay::setFloor(int f) {
  this->floor = f;
}
/*
char TextDisplay::getRace() {
  return race;
}

int TextDisplay::getFloor() {
  return floor;
}

int TextDisplay::getAtk() {
  return Atk;
}
*/
int TextDisplay::getHP() {
  return HP;
}
/*
int TextDisplay::getDef() {
  return Def;
}
*/
int TextDisplay::getGold() {
  return gold;
}

void TextDisplay::setAction(string ac) {
  if(hasPrinted == true) {
    this->action = ac;
    hasPrinted = false;
  } else {
    this->action += " ";
    this->action += ac;
  }
}


void TextDisplay::print(ostream &out) {
  // print the map
  for(int row = 0; row < 25; ++row) {
    for(int col = 0; col < 79; ++ col) {
       out << theDisplay[row][col];
    }
    out << endl;
  }
  
  // print the info
   string str;
  if (race == 's') {
    str = "Shade ";
  } else if (race == 'd') {
    str = "Drow ";
  } else if (race == 'v') {
    str = "Vampire ";
  } else if (race == 't') {
    str = "Troll ";
  } else {
    str = "Goblin ";
  }

  out << left << "Race: " << str << "Gold: ";
  out << getGold() << "                                              ";  
  //out << "Gold: " << getGold();
  out << right << setw(10) << "Floor " << floor << endl;
  out << "HP: " << HP << endl;
  out << "Atk: " << Atk << endl;
  out << "Def: " << Def << endl;
  out << "Action: " << action << endl;
  hasPrinted = true;
}
