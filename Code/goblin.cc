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
#include "goblin.h"
#include "orcs.h"
#include <ctime>
#include <cstdlib>

using namespace std;
Goblin::Goblin():x(0), y(0){
    HP = 110;
    Atk = 15;
    Def = 20;
    maxHP = 110;
    name = "goblin";
    gold = 0;
}

int Goblin::getmaxHP(){
        return maxHP;
}

string Goblin::getName() {
  return this->name;
}

void Goblin::beAttacked(Enemy* e){
    int atk = e->getAtk();
    int def = this->getDef();
    int harm = (100.0 / (100 + def)) * atk;
    int num = rand() % 2;
    if(e->getName() == "orcs") harm = harm + 0.5*harm;
    if(num) this->HP -= harm;
}

void Goblin::setHP(int H){
	 if(H > maxHP) HP = maxHP;
        else {
        HP = H;
        }

}

void Goblin::attack(Enemy* e){
        e->beAttacked(this);
        if(e->getHP() <= 0) gold += 5;
}


int Goblin::getAtk() {
    return this->Atk;
}

int Goblin::getDef() {
    return this->Def;
}

int Goblin::getHP() {
    return this->HP;
}


int Goblin::getGold() {
    return this->gold;
}

int Goblin::getX(){
//  cout<<x<<endl;
    return x;
}

int Goblin::getY(){
//  cout<<y<<endl;
    return y;
}

void Goblin::move(int newx, int newy){
    x = newx;
    y = newy;
  
}

void Goblin::setCoords(int newx, int newy){
    x = newx;
    y = newy;
//cerr << "Player X:" << x << "Y:" << y <<endl;
    
}

void Goblin::useItem(Item* item){
    Player* temp = this;
    item->Apply(temp);
}


void Goblin::changeGold(int val) {
    gold+=val;
}

void Goblin::setRoom(int r) {
  room = r;
}

int Goblin::getRoom() {
 return room;
}

