#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "item.h"
#include "enemy.h"
#include "decorator.h"
#include "wd.h"

using namespace std;

WD::WD(Player* component):Decorator(component){
}


string WD::getName(){
        return comp->getName();
}


int WD::getmaxHP(){
        return comp->getmaxHP();
}

int WD::getAtk(){
//cerr << "go with me" << endl;
    return comp->getAtk();
}

Player* WD::getComp(){
	return comp;
}
int WD::getDef(){
	int temp = comp->getDef() - value;
	if(temp < 0) return 0;
    return temp;
}

void WD::beAttacked(Enemy* e){
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

void WD::setHP(int H){
         if(H > maxHP) HP = maxHP;
        else {
        HP = H;
        }

        comp->setHP(H);
}

void WD::attack(Enemy* e) {
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

void WD::move(int newx, int newy){
	if(name == "troll") HP += 5;
        comp->move(newx, newy);
}

int WD::getX(){
        return comp->getX();
}

int WD::getY(){
        return comp->getY();
}

void WD::useItem(Item* item){
	Player* temp = this;
        item->Apply(temp);
}

int WD::getHP(){
        return comp->getHP();
}

int WD::getGold(){
        return comp->getGold();
}
void WD::setCoords(int newx, int newy){
        comp->setCoords(newx, newy);
}

void WD::setRoom(int r){
        comp->setRoom(r);
}

int WD::getRoom(){
        return comp->getRoom();
}

void WD::changeGold(int val){
        comp->changeGold(val);
}
