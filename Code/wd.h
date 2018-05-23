#ifndef __WD_H__
#define __WD_H__

#include "decorator.h"

class WD: public Decorator{
public:
    WD(Player* component);
    virtual int  getAtk();
    virtual int  getDef();
    virtual void attack(Enemy* e);
    virtual void beAttacked(Enemy* e);
    virtual void move(int newx, int newy);
    virtual int getX();
    virtual int getY();
    virtual void useItem(Item* item);
    virtual int getHP();
    virtual int getGold();
    virtual void setCoords(int newx, int newy);
    virtual void setRoom(int r);
    virtual int getRoom();
    virtual void changeGold(int val);
    virtual void setHP(int H);
    virtual Player* getComp();
    virtual int getmaxHP();
    virtual std::string getName();
};

#endif
