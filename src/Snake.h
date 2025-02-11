#include "Food.h"
#include <deque>
#include <raymath.h>

#ifndef SNAKE_H
#define SNAKE_H
class Snake{
  public:
    bool superMode;
    deque<Vector2> body;
    bool isSnakeDead;
    int score;
    Vector2 direction;
    Snake();
    void Draw();
    void UpdatePos();
    void ChangeDirectionUp();
    void ChangeDirectionDown();
    void ChangeDirectionLeft();
    void ChangeDirectionRight();
    void IncreaseSnakeLength();
    bool HeadCollidesWithFood(Food apple);
    void CheckCollisionWithItselfOrWall();
    void resetGame();
  };

#endif