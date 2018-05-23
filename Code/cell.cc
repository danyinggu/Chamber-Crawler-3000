//
//  main.cpp
//  cell
//
//  Created by YU zhuoran on 2015-07-20.
//  Copyright (c) 2015 YUzhuoran. All rights reserved.
//

#include <iostream>
#include <string>
#include "player.h"
#include "enemy.h"
#include "potion.h"
#include "gold.h"
#include "game.h"
#include "cell.h"
#include "dragon.h"
#include "elf.h"
#include "orcs.h"
#include "dwarf.h"
#include "halfling.h"
#include "merchant.h"
#include "small.h"
#include "merchanthoard.h"
#include "normal.h"
#include "human.h"
#include "dragonhoard.h"
#include "potion.h"
#include "ba.h"
#include "bd.h"
#include "wa.h"
#include "wd.h"

using namespace std;

Cell::Cell():x(0), y(0) {
//    chamber = 0;
    role = '.';
    player = NULL;
    enemy = NULL;
//    potion = NULL;
    g = NULL;
    game = NULL;
}

void Cell::clear(){
//    delete player;
    delete enemy;
//    delete potion;
    delete g;
    role = '.';
    player = NULL;
    enemy = NULL;
    g = NULL;
}

Gold* Cell::getGold() {
  return this->g;
}

/*int Cell::getGold(){
    if(g == NULL) return 0;
    else if(g->valid) {
        int amt = g->value;
        delete g;
        g = NULL;
        return amt;
    }
    else return 0;
}
*/

Enemy* Cell::getEnemy() {
   return enemy;
}

Potion* Cell::getPotion()
 {
  return item;
}
void Cell::setEn(Enemy * e) {
    this->enemy = e;
}

char Cell::getRole(){
    return this->role;
}


///////////new
void Cell::setCoords(int x,int y) {
  this->x = x;
  this->y = y;
}

void Cell::setPlayer(Player *p) {
  this->player = p;
}

void Cell::setState(char role) {
  this->role = role;
}



void Cell::setGame(Game* g){
    game = g;
}

Cell::~Cell(){
    this->clear();
//    cerr<<"cell delete"<<endl;
}

char Cell::getOrigState() {
    return origState;
}

void Cell::setOrigState(char state) {
    this->origState = state;
}
Player* Cell::getPlayer() {
  return this->player;
}

void Cell::setPotion(int p) {
  string type = "";
  if(p == 0) {
    type = "RH";
  } else if (p == 1) {
    type = "BA";
  } else if (p == 2) {
    type = "BD";
  } else if (p == 3) {
    type = "PH";
  } else if (p == 4) {
    type = "WA";
  } else {
    type = "WD";
    }
  this->item = new Potion(x, y, type);
}

void Cell::setEnemy(char role) {
//	cerr << "wodunimeichulai"<<endl;
    if(role == 'H') {
      this->enemy = new Human(x,y);
    }
  else if (role == 'W') {
      this->enemy = new Dwarf(x,y);
    } 
  else if (role == 'E') {
      this->enemy = new Elf(x,y);
    }
  else if (role == 'O') {
      this->enemy = new Orcs(x,y);
    }
  else if (role == 'M') {
      this->enemy = new Merchant(x,y);
    } 
  else if (role == 'D') {
      this->enemy = new Dragon(x,y,NULL);          // this will only happen when map is read from file
    } 
    else if(role == 'L') {
	 this->enemy = new Halfling(x,y);
    }
//	cerr << "doumeiyou"<<endl;
}
        

void Cell::setGold(char go) {
  if(go == 's') {
    this->g = new Small(x,y);
  } else if (go == 'n') {
    this->g = new Normal(x,y);
  } else if (go == 'm') {
    this->g = new merchantHoard(x,y); 
  } else {
    this->g = new dragonHoard(x,y);  
  }
  return;
}


void Cell::setGold() {
  if(g != NULL) delete g;
  g = NULL;
}


void Cell::setEnemy() {
  if(enemy != NULL) delete enemy;
  enemy = NULL;
}

void Cell::setPotion() {
  if(item != NULL) delete item;
  item = NULL;
}






