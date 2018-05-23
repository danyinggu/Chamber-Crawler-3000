#include <iostream>
#include "controller.h"
//#include <ctime>
//#include <cstdlib>
#include "game.h"

//ifstream* Game::input = NULL;

using namespace std;

int main(int argc, char *argv[]) {
  //  cout<<"b" << endl;
    if(argc == 1) {
        Controller c;
    //    cout << "aa" <<endl;
        c.play("");
    } else {
      Controller c;
      c.play(argv[1]);
    }
    return 0;

}
