#ifndef __Vampire_H__
#define __Vampire_H__

#include <iostream>
#include <string>
#include <limits>
#include "player.h"
class Dwarf;

using namespace std;

class Vampire:public Player{
protected:
    int Atk;
    int Def;
    int floor;
    int x;
    int y;
    int gold;
    bool isOrigin;
//////
    int room;
public:
    Vampire();
    virtual void move(int newx, int newy);
    virtual void attack(Enemy* e);
    int getX();
    int getY();
    virtual string getName();
    virtual int getDef();
    virtual int getAtk();
    virtual void beAttacked(Enemy* e);
    virtual void useItem(Item* item);
    int getHP();
    int getGold();
    void setCoords(int newx, int newy);
    void setRoom(int r);
    int getRoom();
    void changeGold(int val);
    virtual void setHP(int H);
    virtual int getmaxHP();
};

#endif
