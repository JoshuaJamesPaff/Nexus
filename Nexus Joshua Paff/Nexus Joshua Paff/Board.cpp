//#include "stdafx.h"
#include "Board.h"
#include "Drawer.h"
#include <string.h>

// constructor calls load baord
Board::Board(void)
{
	loadBoard();
}

// load board method loads a board to the game size
void Board::loadBoard()
{
	for(int i = 0; i < BOARD_HEIGHT; i++)
		for(int j = 0; j < BOARD_WIDTH; j++)
			board[i][j] = 0;
}
 //overlaodes the loadBoard method for specific dimensions
void Board::loadBoard(int x, int y) 
{
	for(int i = 0; i < y; i++)
		for(int j = 0; j < x; j++)
			board[i][j] = 0;
}

//draws the board
void Board::draw()
{
	Drawer::draw(*this);
}
