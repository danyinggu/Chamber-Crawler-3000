#include "vampire.h"
#include "enemy.h"
#include "dwarf.h"
#include <iostream>
#include <string>
#include <cmath>
#include "player.h"
#include "dwarf.h"
#include "item.h"
#include "potion.h"
#include <ctime>
#include <cstdlib>
using namespace std;

Vampire::Vampire():x(0), y(0){
    HP = 50;
    Atk = 25;
    Def = 25;
    name = "vampire";
    maxHP = numeric_limits<int>::max();
    gold = 0;
}

int Vampire::getmaxHP(){
        return maxHP;
}

string Vampire::getName() {
  return this->name;
}

void Vampire::attack(Enemy* e){
    e->beAttacked(this);
    if(e->getName() == "dwarf") HP -= 5;
    else {
	HP += 5;
    }
}

void Vampire::setHP(int H){
	if(H > maxHP) HP = maxHP;
	else {
        HP = H;
        }
}

int Vampire::getAtk() {
    return this->Atk;
}

void Vampire::changeGold(int val) {
    gold+=val;
}

void Vampire::setRoom(int r) {
  room = r;
}

int Vampire::getRoom() {
 return room;
}


int Vampire::getDef() {
    return this->Def;
}

int Vampire::getHP() {
    return this->HP;
}


int Vampire::getGold() {
    return this->gold;
}

int Vampire::getX(){
//  cout<<x<<endl;
    return x;
}

int Vampire::getY(){
//  cout<<y<<endl;
    return y;
}
void Vampire::move(int newx, int newy){
    x = newx;
    y = newy;

}

void Vampire::setCoords(int newx, int newy){
    x = newx;
    y = newy;
//cerr << "Player X:" << x << "Y:" << y <<endl;

}

void Vampire::useItem(Item* item){
    Player* temp = this;
    item->Apply(temp);
}


void Vampire::beAttacked(Enemy* e){
    int atk = e->getAtk();
    int def = this->getDef();
   // srand(unsigned(time(NULL)));
    float harm = (100.0 / (100 + def)) * atk;
    harm = ceil(harm);
    int num = rand() % 2;
    if(num) {
        this->HP -= harm;

//        cerr << "Current HP: " << HP << endl;
    }
    else {
  //      cerr << "Attack Miss!" << endl;
   }
   if(HP <= 0) HP = 0;
}

