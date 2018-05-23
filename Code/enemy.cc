#include <iostream>
#include <string>
#include <cmath>
#include "enemy.h"
#include "player.h"
#include "gold.h"

using namespace std;

Enemy::Enemy(int x, int y):x(x), y(y){
    HP = 140;
    Atk = 20;
    Def = 20;
    updated = false;
    hostile = true;
}

bool Enemy::getHostile(){return hostile;}


int Enemy::getAtk(){
	return Atk;
}

int Enemy::getDef(){
	return Def;
}

int Enemy::getHP(){
	return HP;
}

string Enemy::getName() {
   return name;
}

void Enemy::beAttacked(Player* p){
    int atk = p->getAtk();
    float harm = (100.0 / (100 + Def)) * atk;
    harm = ceil(harm);
    this->HP -= harm;
    if(HP <= 0){
     HP = 0;   
    }
// cerr<< "Current HP!!!" << " " << HP << endl;
}
int Enemy::getX(){
    return this->x;
}
int Enemy::getY(){
    return this->y;
}
void Enemy::attack(Player* p){
    p->beAttacked(this);    
}
void Enemy::setGold(Gold* g){
    gold = g;
}
//int Enemy::getGold(){
  //  return gold->value;
//}
void Enemy::setCoords(int newx, int newy){
    x = newx;
    y = newy;
}

void Enemy::sendGolds(Player* p){
	gold->Apply(p);
        delete gold;
	gold = NULL;
}


Gold* Enemy::getGold() {
  return this->gold;
}

Enemy::~Enemy() {
  if((name != "dragon") && (gold !=NULL)) delete gold;
  gold = NULL;
}

