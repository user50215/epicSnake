#include <raylib.h>

using namespace std;

#ifndef GLOBALS_H
#define GLOBALS_H

// Variables
extern const Color green;
extern const Color darkGreen;
extern const Color red;
extern const Color black;
extern const Color white;
extern const Color pink;
// Ideally these should be all caps, (CELL_SIZE) 
//but I don't want to change all of the variables again
extern const int cellSize;
extern const int cellCount;
extern double timeAlive;
extern double lastUpdateTime;
extern double lastUpdateTimeForKeystroke;

// Functions
bool triggerEvent(double interval);
bool isEnoughTimePassedForAnotherKeystroke(double interval);
#endif