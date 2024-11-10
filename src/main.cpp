#include <raylib.h>
#include "grid.h"

int main() 
{
    
    
    constexpr int screenWidth = 300;
    constexpr int screenHeight = 600;
    Color darkBlue = {44,44,127,255};
    
    
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);
    Grid grid = Grid(); 
    grid.grid[0][0]=1;
    grid.grid[1][0]=2;
    grid.grid[0][1]=7;
    grid.grid[1][9]=6;
    grid.Print();
    while (!WindowShouldClose())
    {   
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw(); 

        EndDrawing();
    
    
    }
    CloseWindow();
}