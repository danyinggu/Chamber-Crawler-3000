#ifndef __Gold_H__
#define __Gold_H__

#include <iostream>
#include <string>
#include "item.h"

class Player;

class Gold: public Item{
protected:
    int x;
    int y;
    int value;
    bool valid;
    bool isSet;
public:
    Gold(int x, int y);
    void setValid();
    bool checkValid();
    virtual void Apply(Player*& p);
    int getX();
    int getY();
    void set();
    bool isSeted();
};

#endif

