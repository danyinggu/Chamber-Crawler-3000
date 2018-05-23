#ifndef __Decorator_H__
#define __Decorator_H__

#include <iostream>
#include <string>
#include "player.h"

class Enemy;

class Decorator:public Player{
protected:
    int value;
    int HP;
    int maxHP;
    std::string name;
    Player* comp;
//    bool isOrigin;
public:
    Decorator(Player* p);
    virtual ~Decorator();
};

#endif
