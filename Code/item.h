#ifndef __Item_H__
#define __Item_H__

#include <iostream>
#include <string>
#include "shade.h"
#include "decorator.h"
#include "ba.h"
#include "bd.h"
#include "wa.h"
#include "wd.h"
class Player;

class Item {
public:
    virtual void Apply(Player*& p)=0;
    virtual ~Item();
};

#endif

