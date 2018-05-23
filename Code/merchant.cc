#include <iostream>
#include <string>
#include "enemy.h"
#include "merchant.h"
#include "player.h"
#include "merchanthoard.h"

Merchant::Merchant(int x, int y):Enemy(x, y){
    HP = 30;
    Atk = 70;
    Def = 5;
    hostile = false;
    name = "merchant";
    gold = new merchantHoard(this->getX(), this->getY());
}


void Merchant::beAttacked(Player* p){
    hostile = true;
    int atk = p->getAtk();
    int harm = (100.0 / (100 + Def)) * atk;
    this->HP -= harm;
    if(HP <= 0){
	HP = 0;
    }
}
