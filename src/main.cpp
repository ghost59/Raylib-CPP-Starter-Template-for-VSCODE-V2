#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"
int main() 
{
    
    
    constexpr int screenWidth = 300;
    constexpr int screenHeight = 600;
    Color darkBlue = {44,44,127,255};
    
    
    InitWindow(screenWidth, screenHeight, "Tetris game");
    SetTargetFPS(60);
    Grid grid = Grid(); 
   
    grid.Print();
    OBlock block = OBlock();
    block.Move(1,2);
   
    while (!WindowShouldClose())
    {   
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw(); 
        
        block.Draw();
        EndDrawing();
    
    
    }
    CloseWindow();
}