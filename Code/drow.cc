#include "drow.h"
#include <iostream>
#include <string>
#include <cmath>
#include "player.h"
#include "enemy.h"
#include "dwarf.h"
#include "item.h"
#include "potion.h"
#include <ctime>
#include <cstdlib>
using namespace std;


Drow::Drow():x(0), y(0){
    HP = 150;
    Atk = 25;
    Def = 15;
    name = "drow";
    maxHP = 150;
    gold = 0;
}

int Drow::getmaxHP(){
        return maxHP;
}

string Drow::getName() {
  return this->name;
}

void Drow::setHP(int H){
	 if(H > maxHP) HP = maxHP;
        else {
        HP = H;
        }

}

int Drow::getAtk() {
    return this->Atk;
}

int Drow::getDef() {
    return this->Def;
}

int Drow::getHP() {
    return this->HP;
}


int Drow::getGold() {
    return this->gold;
}

int Drow::getX(){
//  cout<<x<<endl;
    return x;
}

int Drow::getY(){
//  cout<<y<<endl;
    return y;
}

void Drow::move(int newx, int newy){
    x = newx;
    y = newy;

}


void Drow::setCoords(int newx, int newy){
    x = newx;
    y = newy;
//cerr << "Player X:" << x << "Y:" << y <<endl;

}

void Drow::useItem(Item* item){
    Player* temp = this;
    item->Apply(temp);
}


void Drow::attack(Enemy* e){
//    cerr << "call me? " << endl;
    e->beAttacked(this);
}


void Drow::beAttacked(Enemy* e){
    int atk = e->getAtk();
    int def = this->getDef();
   // srand(unsigned(time(NULL)));
    float harm = (100.0 / (100 + def)) * atk;
    harm = ceil(harm);
    int num = rand() % 2;
    if(num) {
        this->HP -= harm;

  //      cerr << "Current HP: " << HP << endl;
    }
    else {
    //    cerr << "Attack Miss!" << endl;
   }
   if(HP <= 0) HP = 0;
}


void Drow::changeGold(int val) {
    gold+=val;
}

void Drow::setRoom(int r) {
  room = r;
}


int Drow::getRoom() {
 return room;
}

