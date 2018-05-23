#ifndef __Shade_H__
#define __Shade_H__

#include <iostream>
#include <string>
#include "player.h"
class Item;
class Enemy;
class Dwarf;
class Player;

using namespace std;

class Shade:public Player {
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
    Shade();
    virtual void move(int newx, int newy);
    virtual void attack(Enemy* e);
    int getX();
    int getY();
    virtual int getDef();
    virtual int getAtk();
    virtual void beAttacked(Enemy* e);
    virtual void useItem(Item* item);
    int getHP();
    int getGold();
    void setCoords(int newx, int newy);
    void setRoom(int r);
    int getRoom();
    virtual string getName();
    void changeGold(int val);
    virtual void setHP(int H);
    virtual int getmaxHP();
};

#endif
