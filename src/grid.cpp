#include "grid.h"
#include <iostream>
#include "colors.h"
using namespace std; 
Grid::Grid()
{
    numRows = 20; 
    numCols = 10; 
    cellSize = 30; 
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize()
{
    for(int row = 0; row < numRows; row++)
    {
        for(int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0; 
        }
    }
}

void Grid::Print()
{
     for(int row = 0; row < numRows; row++)
    {
        for(int column = 0; column < numCols; column++)
        {
            cout << grid[row][column] << " "; 
        }
        cout << endl;
    }
}


void Grid::Draw()
{
    for(int row=0; row < numRows; row++)
    {
        for(int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 1, row * cellSize+1,cellSize-1,cellSize-1,colors[cellValue]);
        }
    }
}

bool Grid::isCellOutside(int row, int column)
{
    if(row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false;
    }
    return true;
}

bool Grid::isCellEmpty(int row, int column)
{
   if(grid[row][column] == 0)
   {
    return true; 
   }
   return false;
}
