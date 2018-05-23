#include <iostream>
#include <string>
#include "player.h"
#include "normal.h"
#include "enemy.h"
#include "human.h"
#include "normal.h"

Human::Human(int x, int y):Enemy(x, y){
    HP = 140;
    Atk = 20;
    Def = 20;
    name = "human";
    gold = new Normal(this->getX(), this->getY());
    gold2 = new Normal(this->getX(), this->getY());
}


void Human::sendGolds(Player* p){
    gold->Apply(p);
    gold2->Apply(p);
    delete gold;
    delete gold2;
    gold = NULL;
    gold2 = NULL;
}
