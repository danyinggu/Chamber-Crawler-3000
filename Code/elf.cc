#include <iostream>
#include <string>
#include "enemy.h"
#include "player.h"
#include "drow.h"
#include "elf.h"
#include "item.h"
#include "small.h"
#include "normal.h"
#include <ctime>
#include <cstdlib>

Elf::Elf(int x, int y):Enemy(x, y){
    HP = 140;
    Atk = 30;
    Def = 10;
    name = "elf";
    int num = rand() % 2;
    if(num) gold = new Small(this->getX(), this->getY());
    else {
	gold = new Normal(x, y);
    }
    //generate gold to continue
}

void Elf::Attack(Player* p){
	if(p->getName() == "drow") {
		p->beAttacked(this);
	}
	else {
		p->beAttacked(this);
		p->beAttacked(this);
	}
}

