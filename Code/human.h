#include <iostream>
#include <string>
#include "enemy.h"
class Gold;

class Human:public Enemy{
public:
    Gold* gold2;
    Human(int x, int y);
    void sendGolds(Player* p);
};
