#ifndef __Goblin_H__
#define __Goblin_H__

#include <iostream>
#include <string>
#include "player.h"

class Enemy;

using namespace std;

class Goblin:public Player{
protected:
    int Atk;
    int Def;
    int floor;
    int x;
    int y;
    int gold;
//////
    int room;
public:
    Goblin();
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
