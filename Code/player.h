
//  2.h
//  cell
//
//  Created by Yu Zhuoran on 2015-07-20.
//  Copyright. All rights reserved.
//

#ifndef __Player_H__
#define __Player_H__

#include <iostream>
#include <string>

class Item;
class Enemy;
class Dwarf;

class Player {
protected:
    int HP;
    int maxHP;
//    bool isOrigin;
    Player* comp;
    std::string name;
public:
    Player();
    virtual void move(int newx, int newy)=0;
    virtual void attack(Enemy* e)=0;
    virtual int getX()=0;
    virtual int getY()=0;
    virtual int getDef()=0;
    virtual int getAtk()=0;
    virtual void beAttacked(Enemy* e)=0;
    virtual void useItem(Item* item)=0;
    virtual int getHP()=0;
    virtual int getGold()=0;
    virtual void setCoords(int newx, int newy)=0;
    virtual void setRoom(int r)=0;
    virtual int getRoom()=0;
    virtual void changeGold(int val)=0;
    virtual void setHP(int H)=0;
    virtual Player* getComp();
    virtual int getmaxHP();
    virtual std::string getName();
    friend class Potion;
};

#endif

