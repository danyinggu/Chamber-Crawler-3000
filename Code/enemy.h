#ifndef __Enemy_H__
#define __Enemy_H__

#include <iostream>
#include <string>


class Player;
class Gold;

class Enemy {
protected:
    bool hostile;
    int x;
    int y;
    Gold* gold;
    int HP;
    int Atk;
    int Def;
    std::string name;
public:
    bool updated;
    Enemy(int x, int y);
    ~Enemy();
    virtual void beAttacked(Player* p);
    virtual void attack(Player* p);
    virtual void sendGolds(Player* p);
    virtual int getAtk();
    virtual int getDef();
    virtual int getHP();
    int getX();
    int getY();
    bool getHostile();
    void setGold(Gold* g);
    Gold* getGold();
    std::string getName();
    void setCoords(int newx, int newy);
};

#endif
