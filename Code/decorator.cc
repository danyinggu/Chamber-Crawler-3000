#include <iostream>
#include <string>
#include "decorator.h"
#include "player.h"
#include "item.h"
#include "enemy.h"
#include <limits>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

Decorator::Decorator(Player* p):comp(p){
        value = 5;
//        isOrigin = false;
        HP = p->getHP();
        name = p->getName();
	if(name == "vampire") maxHP = numeric_limits<int>::max();
        else {
		maxHP = HP;
	}
	if(name == "drow") value = 8;
}

Decorator::~Decorator(){
	delete comp;
}
