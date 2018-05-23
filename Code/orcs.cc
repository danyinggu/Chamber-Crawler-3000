#include <iostream>
#include <string>
#include "orcs.h"
#include "enemy.h"
#include "item.h"
#include "small.h"
#include "normal.h"
#include <ctime>
#include <cstdlib>

Orcs::Orcs(int x, int y):Enemy(x, y){
    HP = 180;
    Atk = 30;
    Def = 25;
    name = "orcs";
    int num = rand () % 2;
    if(num == 0) gold = new Small(x, y);
    else {
        gold = new Normal(x, y);
    }
}
