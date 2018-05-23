#include "potion.h"
#include "player.h"
#include "ba.h"
#include "bd.h"
#include "wa.h"
#include "wd.h"

using namespace std;


Potion::Potion(int x, int y, string name):x(x), y(y), name(name){
}

void Potion::Apply(Player*& p){
	int newHP;
    if(name == "RH") {
	if(p->getName() == "drow"){
	newHP = min(p->getHP()+15, p->getmaxHP());
        }
	else {
        newHP = min(p->getHP()+10, p->getmaxHP());
	}
        p->setHP(newHP);
    }
    else if(name == "PH") {
	if(p->getName() == "drow"){
        newHP = max(p->getHP()-15, 0);
        }
	else {
        newHP = max(p->getHP()-10, 0);
	}
        p->setHP(newHP);
    }
    else if(name == "BA") {
        p = new BA(p);
    }
    else if(name == "BD") {
        p = new BD(p);
    }
    else if(name == "WA") {
        p = new WA(p);
    }
    else {
	 p = new WD(p);
	}
    if(p->getName() == "troll"){
	newHP = 5+ p->getHP();
        p->setHP(newHP);
    }
}

string Potion::getName(){
   return name;
}
