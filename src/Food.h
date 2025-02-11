#include "globals.h"
#include <iostream>

using namespace std;

#ifndef FOOD_H
#define FOOD_H

class Food{
    public:
        Vector2 pos;
        Food();
        void Draw();
        Vector2 GenerateRandomPos();
};

#endif