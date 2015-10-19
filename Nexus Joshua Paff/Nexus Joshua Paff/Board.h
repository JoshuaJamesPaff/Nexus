#pragma once
#ifndef _BOARD
#define _BOARD


#define BLOCK_SIZE 50
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 10

class Board
{
	char board[BOARD_HEIGHT][BOARD_WIDTH];

public:
	Board(void);	
	void loadBoard();
	void loadBoard(int, int);	
	void draw();
	
};



#endif 
