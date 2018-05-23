#include <iostream>
#include <string>
#include "vampire.h"
#include "dwarf.h"
#include "enemy.h"
#include "item.h"
#include "small.h"
#include "normal.h"
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

Dwarf::Dwarf(int x, int y):Enemy(x, y){
    HP = 100;
    Atk = 20;
    Def = 30;
    name = "dwarf";
    int num = rand () % 2;
    if(num == 0) gold = new Small(x, y);
    else {
	gold = new Normal(x, y);
    }
}


