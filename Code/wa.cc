#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "item.h"
#include "enemy.h"
#include "decorator.h"
#include "wa.h"

using namespace std;

WA::WA(Player* component):Decorator(component){
}


string WA::getName(){
        return comp->getName();
}


int WA::getmaxHP(){
        return comp->getmaxHP();
}

int WA::getAtk(){
//cerr << "go with me" << endl;
	int temp = comp->getAtk() - value;
	if(temp < 0) return 0;
    return temp;
}

Player* WA::getComp(){
	return comp;
}
int WA::getDef(){
	int temp = comp->getDef();
    return temp;
}

void WA::beAttacked(Enemy* e){
    int atk = e->getAtk();
    int def = this->getDef();
    float harm = (100.0 / (100 + def)) * atk;
    harm = ceil(harm);
    int num = rand() % 2;
    if(num) {
        HP -= harm;
	setHP(HP);
  //      cerr << "Current HP: " << HP << endl;
    }
    else {
    //    cerr << "Attack Miss!" << endl;
   }
   if(HP <= 0) {
        HP = 0;
        setHP(HP);
   }
}

void WA::setHP(int H){
         if(H > maxHP) HP = maxHP;
        else {
        HP = H;
        }

        comp->setHP(H);
}

void WA::attack(Enemy* e) {
        if(name == "vampire"){
                if(e->getName() == "dwarf") setHP(HP-5);
                else {
                        setHP(HP + 5);
                }
        }
	if(name == "troll") setHP(HP+5);
        e->beAttacked(this);
        if(name == "goblin") {
                if(e->getHP() <= 0) comp->changeGold(5);
        }

}

void WA::move(int newx, int newy){
	if(name == "troll") HP += 5;
        comp->move(newx, newy);
}

int WA::getX(){
        return comp->getX();
}

int WA::getY(){
        return comp->getY();
}

void WA::useItem(Item* item){
	Player* temp = this;
        item->Apply(temp);
}

int WA::getHP(){
        return comp->getHP();
}

int WA::getGold(){
        return comp->getGold();
}
void WA::setCoords(int newx, int newy){
        comp->setCoords(newx, newy);
}

void WA::setRoom(int r){
        comp->setRoom(r);
}

int WA::getRoom(){
        return comp->getRoom();
}

void WA::changeGold(int val){
        comp->changeGold(val);
}
