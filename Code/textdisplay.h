#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

class TextDisplay {
    char **theDisplay;
    int floor;
    char race;
    int gold;
    int Atk;
    int Def;
    int HP;
    bool hasPrinted;
    string action;
    void clearDisplay();
  public:
    TextDisplay();
    ~TextDisplay();
    
    void notify(int x, int y, char state);
    void print(ostream &out);

    void setRace(char r);
    void setFloor(int f);

    void setVal(int hp, int def, int atk, int g);
    int getGold();
    int getHP();
    void setAction(string ac);
};

#endif
