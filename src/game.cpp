#include "game.h"
#include <random>
Game::Game()
{
    grid = Grid(); 
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock(); 
}

Block Game::GetRandomBlock()
{
    if(blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int randomIdnex = rand() % blocks.size();
    Block block = blocks[randomIdnex];
    blocks.erase(blocks.begin() + randomIdnex); 
    return block; 
}

std::vector<Block> Game::GetAllBlocks()
{
    return {IBlock(),LBlock(),OBlock(),SBlock(),TBlock(),ZBlock()};
}

void Game::Draw()
{
    grid.Draw(); 
    currentBlock.Draw();
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed(); 
    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    case KEY_RIGHT:
        MoveBlockRight();
        break;
    case KEY_DOWN:
        MoveBlockDown();
        break;
    case KEY_UP:
        RotateBlock();
        break;
    }
}

void Game::MoveBlockLeft()
{
    currentBlock.Move(0,-1);
    if(isBlockOutside())
    {
        currentBlock.Move(0,1);
    }
}

void Game::MoveBlockRight()
{
    currentBlock.Move(0,1);
    if(isBlockOutside())
    {
        currentBlock.Move(0,-1);
    }
}

void Game::MoveBlockDown()
{
    currentBlock.Move(1,0);
    if(isBlockOutside() || BlockFits() == false)
    {
        currentBlock.Move(-1,0); 
        LockBlock();
    }
}

bool Game::isBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPosition();
    for(Position item: tiles)
    {
        if(grid.isCellOutside(item.row,item.column))
        {
            return true; 
        }
    }
    return false;
}

void Game::RotateBlock()
{
    currentBlock.Rotate(); 
    if(isBlockOutside())
    {
        currentBlock.undoRotation();
    }

}

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPosition(); 
    for(Position item: tiles)
    {
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    nextBlock = GetRandomBlock();
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPosition();
    for(Position item: tiles)
    {
        if(grid.isCellEmpty(item.row,item.column) == false)
        {
            return false; 
        }
    }
    return true;
}
