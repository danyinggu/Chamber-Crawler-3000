//
//  2.m
//  cell
//
//  Created by YU Zhuoran on 2015-07-20.
//  Copyright (c)

#include <iostream>
#include <string>
#include <cmath>
#include "player.h"
#include "enemy.h"
#include "dwarf.h"
#include "item.h"
#include "shade.h"
#include "potion.h"
#include <ctime>
#include <cstdlib>

using namespace std;

Shade::Shade():x(0), y(0){
    name = "default";
    floor = 1;
    maxHP = 125;
    HP = 125;
    Atk = 25;
    Def = 25;
    gold = 0;
}

int Shade::getmaxHP(){
	return maxHP;
}

string Shade::getName() {
  return this->name;
}

void Shade::setHP(int H){
	if(H > maxHP) HP = maxHP;
	else {
	HP = H;
	}
}


int Shade::getAtk() {
    return this->Atk;
}

int Shade::getDef() {
    return this->Def;
}

int Shade::getHP() {
    return this->HP;
}


int Shade::getGold() {
    return this->gold;
}

int Shade::getX(){
//  cout<<x<<endl;
    return x;
}

int Shade::getY(){
//  cout<<y<<endl;
    return y;
}

void Shade::move(int newx, int newy){
    x = newx;
    y = newy;
  
}

void Shade::setCoords(int newx, int newy){
    x = newx;
    y = newy;
//cerr << "Player X:" << x << "Y:" << y <<endl;
    
}

void Shade::useItem(Item* item){
    Player* temp = dynamic_cast<Player *>(this);
    item->Apply(temp);
}


void Shade::attack(Enemy* e){
    e->beAttacked(this);
}


void Shade::beAttacked(Enemy* e){
    int atk = e->getAtk();
    int def = this->getDef();
   // srand(unsigned(time(NULL)));
    float harm = (100.0 / (100 + def)) * atk;
    harm = ceil(harm);
    int num = rand() % 2;
    if(num) {
	this->HP -= harm;
        
//	cerr << "Current HP: " << HP << endl;
    }
    else {
//	cerr << "Attack Miss!" << endl;
   }
   if(HP <= 0) HP = 0;
}


void Shade::changeGold(int val) {
    gold+=val;
}

void Shade::setRoom(int r) {
  room = r;
}

int Shade::getRoom() {
 return room;
}

