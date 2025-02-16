#include <raylib.h>
#include "game.h"
double lastupdatetime = 0; 
bool EvenTriggered(double interval)
{
    double currenttime = GetTime(); 
    if(currenttime - lastupdatetime >= interval)
    {
        lastupdatetime = currenttime; 
        return true; 
    }
    return false;
}
int main() 
{
    
    
    constexpr int screenWidth = 300;
    constexpr int screenHeight = 600;
    Color darkBlue = {44,44,127,255};
    
    
    InitWindow(screenWidth, screenHeight, "Tetris clone");
    SetTargetFPS(60);
    Game game = Game();
   
  
    
   
   
    while (!WindowShouldClose())
    {   
        game.HandleInput();
        if(EvenTriggered(0.2))
        {
            game.MoveBlockDown();
        }
        
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    
    
    }
    CloseWindow();
}