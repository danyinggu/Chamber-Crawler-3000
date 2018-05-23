#include <iostream>
#include <string>
#include "gold.h"
#include "player.h"

using namespace std;

Gold::Gold(int x, int y):x(x), y(y){
    valid = true;
    isSet = false;
}

/*
void Gold::setCoords(int newx, int newy){
    x = newx;
    y = newy;
}
*/

void Gold::setValid(){
    valid = true;
}

bool Gold::checkValid(){
    return valid;
}

void Gold::Apply(Player*& p){
    if(checkValid()){
        p->changeGold(value);
    }
}

int Gold::getX() {
  return this->x;
}

int Gold::getY() {
  return this->y;
}

void Gold::set() {
  isSet = true;
}

bool Gold::isSeted() {
  return isSet;
}
