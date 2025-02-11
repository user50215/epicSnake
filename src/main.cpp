#include "Snake.h"

int main(){
  //  This starts the game and makes console window, beginning part
  InitWindow(cellSize * cellCount, cellSize * cellCount, "EPIC SNAKE");
  SetTargetFPS(60);
  Food apple;
  Snake snake;

  // Sounds
  // After bass drop on epic music(around 30s) change background color to black and increase
  // speed of snake to 1.5x
  bool loadEpicMusic = true;
  bool canPlaySadMusic = true;
  InitAudioDevice();
  Sound epicMusic = LoadSound("../sounds/musicEpic.mp3");
  Sound eatSound = LoadSound("../sounds/eat.wav");
  Sound sadMusic = LoadSound("../sounds/musicSad.mp3");
  Sound pan = LoadSound("../sounds/pan.mp3");
  bool getTimeSinceStart = true;
  double timeSinceStart = GetTime();
  
  // Images
  Texture2D texture;
  Image sadFace = LoadImage("../graphics/sadFace.png");
  texture = LoadTextureFromImage(sadFace);
  UnloadImage(sadFace);
  Texture2D sweat;
  Image sweaty = LoadImage("../graphics/sweat.jpg");
  sweat = LoadTextureFromImage(sweaty);
  UnloadImage(sweaty);

  bool inStartMenu = true;

  // STARTING GAME LOOP  
  while(WindowShouldClose() == false){
    if(inStartMenu == true){
      BeginDrawing();
      ClearBackground(red);DrawText("Welcome to Epic Snake by ALEX", 3*cellCount, 5*cellCount, 40, white);
      DrawText("Press r to start game", 10*cellCount/2, 8*cellCount, 40, white);
      EndDrawing();
      if(IsKeyPressed(KEY_R)){
        inStartMenu = false;
      }
    }
    else if(snake.isSnakeDead == false){
      BeginDrawing();
      double currentTime = GetTime();
      if(getTimeSinceStart){
        timeSinceStart = GetTime();
        getTimeSinceStart = false;
      }
      if(currentTime - timeSinceStart >= 32.5){
        snake.superMode = true;
        ClearBackground(pink);
      }
      else ClearBackground(green);
      DrawText(TextFormat("%i", snake.score), cellSize, cellSize, 60, black);
      if(snake.superMode) DrawTexture(sweat, 170, 150, GREEN);
      apple.Draw(); 
      snake.Draw();
      if(loadEpicMusic == true){
        PlaySound(epicMusic);
        loadEpicMusic = false;
      }
      if(IsKeyPressed(KEY_UP) && snake.direction.y != 1 && isEnoughTimePassedForAnotherKeystroke(.05)) snake.ChangeDirectionUp();
      else if(IsKeyPressed(KEY_DOWN) && snake.direction.y != -1 && isEnoughTimePassedForAnotherKeystroke(.05)) snake.ChangeDirectionDown();
      else if(IsKeyPressed(KEY_RIGHT) && snake.direction.x != -1 && isEnoughTimePassedForAnotherKeystroke(.05)) snake.ChangeDirectionRight();
      else if(IsKeyPressed(KEY_LEFT) && snake.direction.x != 1 && isEnoughTimePassedForAnotherKeystroke(.05)) snake.ChangeDirectionLeft();
      // Increase length of snake by 1 if the snake eats an apple
      if(snake.superMode == false){
        if(triggerEvent(.1)){
          snake.UpdatePos();
          if(snake.HeadCollidesWithFood(apple)) {
            snake.IncreaseSnakeLength();
            PlaySound(eatSound);
            ++snake.score;
            apple.pos = apple.GenerateRandomPos();
          }
        }
      }
      else{
        if(triggerEvent(.05)){
          snake.UpdatePos();
          if(snake.HeadCollidesWithFood(apple)) {
            snake.IncreaseSnakeLength();
            PlaySound(eatSound);
            ++snake.score;
            apple.pos = apple.GenerateRandomPos();
          }
        }
      }
      snake.CheckCollisionWithItselfOrWall();
      // This ends the current drawing, but as long as loop is true then another drawing will
      // begin right after
      EndDrawing();
    }
    // If snake is dead this will activate which turns screen red, maybe make it scary and add
    // text
    else{
      StopSound(epicMusic);
      BeginDrawing();
      ClearBackground(red);
      if(canPlaySadMusic == true){
        PlaySound(pan);
        PlaySound(sadMusic);
        canPlaySadMusic = false;
      }
      DrawTexture(texture, 8*cellCount, 300, WHITE);
      DrawText("YOU DIED!!!!", 12*cellCount/2, 5*cellCount, 80, white);
      DrawText("Press r to reset", 17*cellCount/2, 8*cellCount, 40, white);
      EndDrawing();
      if(IsKeyPressed(KEY_R)){
        snake.resetGame();
        loadEpicMusic = true;
        canPlaySadMusic = true;
        getTimeSinceStart = true;
        snake.superMode = false;
        StopSound(sadMusic);
      }
    }
  }
    
  // Loop ends once user presses esc or the close button on window, after that close window and
  // end program
  UnloadTexture(texture);
  UnloadSound(eatSound);
  UnloadSound(epicMusic);
  CloseAudioDevice();
  CloseWindow();
  return 0;
}
