#ifndef _GAME_H_
#define _GAME_H_
#include <iostream>
#include "cell.h"
#include <ctime>
#include <sstream>
#include <cstdlib>
#include "player.h"
class Controller;

using namespace std;

class Game {
  int floor;
  Cell **theFloor;
  Player *player;
  Controller *controller;
//  static ifstream* input;
  char inputType;
  bool hostile;
  void clearFloor();

public:
  Game();
  ~Game();
  void notify(int x, int y, char newState);
  void init(Controller *controller, char inputType, ifstream* input);
  void initMap(ifstream* input);
  void selectRoom(char role);
  void initRoom(int roomNum, char role);
//  void setCell(int x, int y, char newState);
  Player* getPlayer();  
  void initE();
  void initEnemy();
  void movePlayer(string direction);
  void findPotion(string direction);
  void attack(string direction);
  void enemyAction();
  void setHostile();
  bool isHostile();
  void createPlayer(string race);
  void setDragon(int x,int y);  
  void setDragon();
  void setPlayer(Player* p);
};

#endif

