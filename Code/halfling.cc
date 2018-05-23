#include <iostream>
#include <string>
#include "halfling.h"
#include "player.h"
#include "item.h"
#include "enemy.h"
#include "small.h"
#include "normal.h"
#include <ctime>
#include <cstdlib>

using namespace std;

Halfling::Halfling(int x, int y):Enemy(x, y){
    HP = 100;
    Atk = 15;
    Def = 20;
    name = "halfling";
    int num = rand () % 2;
    if(num == 0) gold = new Small(x, y);
    else {
        gold = new Normal(x, y);
    }
    //generate gold to continue
}

void Halfling::beAttacked(Player* p){
    int atk = p->getAtk();
    int def = this->Def;
//    srand(unsigned(time(NULL)));
    int harm = (100.0 / (100 + def)) * atk;
    int num = rand() % 2;
    if(num) this->HP -= harm;
    if(HP <= 0) HP = 0;
}
