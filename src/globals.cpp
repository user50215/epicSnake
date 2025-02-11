#include "globals.h"

// Variables
const Color green = {173, 204, 96, 255};
const Color darkGreen = {43, 51, 24, 255};
const Color red = {255, 0, 0, 255};
const Color black = {0, 0, 0, 255};
const Color white = {255, 255, 255, 255};
const Color pink = {255, 105, 180, 255};
const int cellSize = 30;
const int cellCount = 25;
double lastUpdateTime = 0;
double lastUpdateTimeForKeystroke = 0;

// Function for checking when to move snake
bool triggerEvent(double interval){
  double currentTime = GetTime();
  if(currentTime - lastUpdateTime >= interval){
    lastUpdateTime = currentTime;
    return true;
  }
  else return false;
}
bool isEnoughTimePassedForAnotherKeystroke(double interval){
  double currentTime = GetTime();
  if(currentTime - lastUpdateTimeForKeystroke >= interval){
    lastUpdateTimeForKeystroke = currentTime;
    return true;
  }
  else return false;
}