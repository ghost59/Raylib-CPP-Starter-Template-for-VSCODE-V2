#include "block.h"
#include "position.h"

class LBlock: public Block{
    public:
        LBlock()
        {
            id = 1; 
            cells[0] ={Position(0,2),Position(1,0),Position(1,1),Position(1,2)};
            cells[1] = {Position(0,1),Position(1,1),Position(2,1),Position(2,2)};
            cells[2] = {Position(1,0),Position(1,1),Position(1,2),Position(2,0)};
            cells[3] = {Position(0,0),Position(0,1),Position(1,1),Position(2,1)};
        } 
};

class IBlock: public Block
{
    public:
        IBlock()
        {
            id = 2; 
            cells[0] = {Position(1,0),Position(1,1),Position(1,2),Position(1,3)};
            cells[1] = {Position(0,2),Position(1,2),Position(2,2),Position(3,2)};
            cells[0] = {Position(2,0),Position(2,1),Position(2,2),Position(2,3)};
            cells[0] = {Position(0,2),Position(1,1),Position(2,2),Position(3,1)};
        }
};


class OBlock: public Block
{
    public:
        OBlock()
        {
            id = 3; 
            cells[0] = {Position(0,0),Position(0,1),Position(1,0),Position(1,1)};
            
        }
};

class SBlock: public Block
{
    public:
        SBlock()
        {
            id = 3; 
            cells[0] = {Position(0,1),Position(0,2),Position(1,0),Position(1,1)};
            cells[1] = {Position(0,1),Position(1,1),Position(1,2),Position(2,2)};
            cells[2] = {Position(1,1),Position(1,2),Position(2,0),Position(2,1)};
            cells[3] = {Position(0,0),Position(0,1),Position(1,1),Position(2,1)};
        }
};

class TBlock: public Block
{
    public:
        TBlock()
        {
            id = 4; 
            cells[0] = {Position(0,1),Position(1,0),Position(1,1),Position(1,2)};
            cells[1] = {Position(0,1),Position(1,1),Position(1,2),Position(2,1)};
            cells[2] = {Position(1,0),Position(1,1),Position(1,2),Position(2,1)};
            cells[3] = {Position(0,1),Position(1,0),Position(1,1),Position(2,1)};
        }
};

class ZBlock: public Block
{
    public:
        ZBlock()
        {
            id = 3; 
            cells[0] = {Position(0,0),Position(0,1),Position(1,1),Position(1,2)};
            cells[1] = {Position(0,2),Position(1,1),Position(1,2),Position(2,1)};
            cells[2] = {Position(2,0),Position(2,1),Position(2,1),Position(2,2)};
            cells[3] = {Position(0,0),Position(0,1),Position(1,1),Position(2,1)};
        }
};