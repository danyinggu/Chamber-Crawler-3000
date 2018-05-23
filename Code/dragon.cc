#include <iostream>
#include <string>
#include "enemy.h"
#include "dragon.h"
#include "dragonhoard.h"

Dragon::Dragon(int x,int y,Gold *g):Enemy(x, y){
    HP = 150;
    Atk = 20;
    Def = 20;
    gold = g;
    name = "dragon";
}


