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
#include "potion.h"
#include "troll.h"
#include <ctime>
#include <cstdlib>

using namespace std;

Troll::Troll():x(0), y(0){
    HP = 120;
    Atk = 25;
    Def = 15;
    name = "troll";
    maxHP = 120;
    gold = 0;
}

int Troll::getmaxHP(){
        return maxHP;
}

string Troll::getName() {
  return this->name;
}

void Troll::setHP(int H){
       if(H > maxHP) HP = maxHP;
        else {
        HP = H;
        }

}

void Troll::move(int newx, int newy){
        x = newx;
        y = newy;
        HP += 5;
        if(HP >= maxHP) HP = maxHP;
}

int Troll::getAtk() {
    return this->Atk;
}

int Troll::getDef() {
    return this->Def;
}

int Troll::getHP() {
    return this->HP;
}


int Troll::getGold() {
    return this->gold;
}

int Troll::getX(){
//  cout<<x<<endl;
    return x;
}

int Troll::getY(){
//  cout<<y<<endl;
    return y;
}

void Troll::setCoords(int newx, int newy){
    x = newx;
    y = newy;
//cerr << "Player X:" << x << "Y:" << y <<endl;
    
}

void Troll::useItem(Item* item){
    Player* temp = this;
    item->Apply(temp);
}


void Troll::attack(Enemy* e){
//    cerr << "call me? " << endl;
    HP += 5;
        if(HP >= maxHP) HP = maxHP;
    e->beAttacked(this);
}


void Troll::beAttacked(Enemy* e){
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


void Troll::changeGold(int val) {
    gold+=val;
}

void Troll::setRoom(int r) {
  room = r;
}

int Troll::getRoom() {
 return room;
}

