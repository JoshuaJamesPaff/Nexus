#include "Board.h"
#include "Drawer.h"


Board::Board(void)
{
	initBoard();
}

void Board::initBoard()
{
	for(int i = 0; i < BOARD_HEIGHT; i++)
		for(int j = 0; j < BOARD_WIDTH; j++)
		{
			boardArray[i][j] = 0;
		}
}

int Board::cellType(int x, int y)
{
	return boardArray[x][y];
}

//draws board
void Board::draw()
{
	Drawer::draw(*this);
}

//changes color of induvidual cell
void Board::changeCell(int x, int y, int colour)
{
	boardArray[x][y] = colour;
	checkLines(x,y);
}

//checks and clears lines that have 5 in a row
int Board::deleteLines(int x, int y)
{
	return x+y;
}

void Board::checkLines(int x, int y){
}


