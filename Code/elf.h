#ifndef __Elf_H__
#define __Elf_H__

#include <iostream>
#include <string>
#include "enemy.h"

class Drow;

class Elf:public Enemy{
public:
    Elf(int x, int y);
    void Attack(Player* p);
};

#endif
