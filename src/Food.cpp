#include "Food.h"

Food::Food(){
    pos = GenerateRandomPos();
}
void Food::Draw(){
    DrawRectangle(pos.x * cellSize, pos.y * cellSize, cellSize, cellSize, red);
}
Vector2 Food::GenerateRandomPos(){
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);
    return Vector2{x, y};
}