//
//  1.h
//  cell
//
//  Created by Yu Zhuoran on 2015-07-20.
//  Copyright (c) 2015 Yu Zhuoran . All rights reserved.
//

#ifndef __CELL__
#define __CELL__

#include <iostream>
#include <string>

class Player;
class Game;
class Enemy;
class Potion;
class Gold;


class Cell {
    int x;
    int y;;
    char role;
    char origState;
    Gold* g;
    Player* player;
    Enemy* enemy;
    Potion* item;
    Game* game;
    void clear();
public:
    Cell();
    ~Cell();
 
    void setCoords(int x, int y);
    void setPlayer(Player *p);
    void setState(char role);
    char getRole();
    char getOrigState();
    void setOrigState(char state);
    Gold * getGold();
    void setGold();
    void setGame(Game *g);
    void setPotion(int p);
    void setEnemy(char role);
    void setGold(char go);
    Enemy* getEnemy();
    void setEnemy();
    Potion* getPotion();
    void setPotion();
    void setEn(Enemy* e);
    Player* getPlayer();
};

#endif

