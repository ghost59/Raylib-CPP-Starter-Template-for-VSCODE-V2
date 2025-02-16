#include "block.h"

Block::Block()
{
    cellSize = 30; 
    rotationState = 0; 
    colors = GetCellColors();
    rowOffset = 0; 
    columnOffset = 0;  
}
void Block::Draw()
{
    std::vector<Position> tiles = GetCellPosition();
    for(Position item: tiles)
    {
        DrawRectangle(item.column * cellSize + 1, item.row * cellSize +1, cellSize -1, cellSize -1, colors[id]);
    }
}

void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
    
}

std::vector<Position>Block::GetCellPosition()
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> moveTiles; 
    for(Position item: tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        moveTiles.push_back(newPos);
    }
    return moveTiles;
}

void Block::Rotate()
{
    rotationState ++; 
    if(rotationState == cells.size())
    {
        rotationState = 0; 

    }
}

void Block::undoRotation()
{
    rotationState --; 
    if(rotationState == -1)
    {
        rotationState = cells.size() - 1; 
    }
}
