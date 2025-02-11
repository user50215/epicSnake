#include "Snake.h"

Snake::Snake(): body(), isSnakeDead(false), score(0), superMode(false), direction({1, 0}){
  body.push_back({6, 9});
  body.push_back({5, 9});
  body.push_back({4, 9});
}

void Snake::Draw(){
  for(int index = 0; index < body.size(); ++index){
    int x = body[index].x;
    int y = body[index].y;
    DrawRectangle(x*cellSize, y*cellSize, cellSize, cellSize, darkGreen);
    // Specific code for drawing head
    if(index == 0) {
      int x = body[index].x;
      int y = body[index].y;
      DrawRectangle(x*cellSize, y*cellSize, 10, 10, red);
    }
  }
}
void Snake::UpdatePos(){
  // Remove tail and update the front position. THIS FUNCTION IS GENIUS!! You dont have to worry about
  // the other parts moving around, because ONLY THE HEAD GETS UPDATED. Super simple.
  body.pop_back();
  body.push_front(Vector2Add(body[0], direction));
}
void Snake::ChangeDirectionUp(){
  direction = {0, -1};
}
void Snake::ChangeDirectionDown(){
  direction = {0, 1};
}
void Snake::ChangeDirectionLeft(){
  direction = {-1, 0};
}
void Snake::ChangeDirectionRight(){
  direction = {1, 0};
}
void Snake::IncreaseSnakeLength(){
  // First find the tail, then add 1 body block to left of it
  Vector2 tail = body[body.size() - 1];
  Vector2 newTail = (Vector2Subtract(tail, {-1, 0}));
  body.push_back(newTail);
}
bool Snake::HeadCollidesWithFood(Food apple){
  Vector2 head = body[0];
  if(head == apple.pos) return true;
  else return false;
}
void Snake::CheckCollisionWithItselfOrWall(){
  Vector2 head = body[0];
  if(head.x < 0 || head.x >= cellCount) isSnakeDead = true;
  if(head.y < 0 || head.y >= cellCount) isSnakeDead = true;
  // Now loop through body to check if head collides with it. DO NOT START AT 0 BECAUSE HEAD IS
  // AT INDEX 0, WHICH MEANS THE IF STATEMENT WILL ALWAYS RETURN TRUE
  for(int index = 1; index < body.size(); ++index){
    if(head.x == body[index].x && head.y == body[index].y){
      isSnakeDead = true;
    }
  }
}
void Snake::resetGame(){
  // Reset snake body, then just set isSnakeDead to false. That will enter if statement which
  // will just run the game like normal, but with the new snake body and score
  body.clear();
  body.push_back({6, 9});
  body.push_back({5, 9});
  body.push_back({4, 9});
  direction = {1, 0};
  score = 0;
  isSnakeDead = false;
}