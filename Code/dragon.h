#ifndef __DRAGON_H__
#define __DRAGON_H__
#include <iostream>
#include <string>
#include "enemy.h"


class Player;
class Gold;

class Dragon:public Enemy{
  public:
//    dragonHoard* mine;
    Dragon(int x, int y,Gold* g);
};


#endif
