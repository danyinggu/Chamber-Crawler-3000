#ifndef __Potion_H__
#define __Potion_H__

#include <iostream>
#include <string>
#include "item.h"

class Potion:public Item {
    int x;
    int y;
    std::string name;
public:
    Potion(int x, int y, std::string name);
    void Apply(Player*& p);
    std::string getName();
};

#endif
