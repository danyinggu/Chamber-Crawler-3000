#ifndef __Halfling_H__
#define __Halfling_H__

#include <iostream>
#include <string>
#include "enemy.h"

class Player;

class Halfling:public Enemy{
public:
    Halfling(int x, int y);
    void beAttacked(Player* p);
};

#endif
