#ifndef __DragonHoard__
#define __DragonHoard__

#include "gold.h"
#include "dragonhoard.h"
class Dragon;


class dragonHoard : public Gold{
    Dragon* d;
public:
    dragonHoard(int x, int y);
    void changeValidity();
};

#endif

