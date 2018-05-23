// Controller.h
#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <iostream>
#include "game.h"
#include "textdisplay.h"

using namespace std;

class Controller {
    TextDisplay *td;
    Game *game;
   
    int floorNum;
    string fileName;
    bool isUp;
//    ifstream input;
  public:

    Controller();
    ~Controller();
    
    void play(string inFile);
    int getFloor();
    void notify(int x, int y, char role);
    void notifyAction(string ac);
    void notifyPlayer(int hp,int deg,int atk,int g);   
    
    TextDisplay* getTD();    
    void restart();
    void setUp();            // called by game
 
};

#endif
    

