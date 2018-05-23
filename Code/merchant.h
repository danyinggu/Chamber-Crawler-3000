#ifndef __Merchant_H__
#define __Merchant_H__

#include <iostream>
#include <string>
#include "enemy.h"

class Merchant:public Enemy{
public:
    Merchant(int x, int y);
    void beAttacked(Player* p);
};

#endif
