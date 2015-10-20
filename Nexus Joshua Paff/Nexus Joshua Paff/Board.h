#pragma once
#ifndef _BOARD
#define _BOARD



#define BLOCK_SIZE 40
#define BOARD_WIDTH 9
#define BOARD_HEIGHT 9



class Board
{
	int boardArray[BOARD_WIDTH][BOARD_HEIGHT];

public:
	Board(void);
	void initBoard();
	int cellType(int, int);
	void draw();
	void changeCell(int, int, int);
	int deleteLines(int, int);
	void checkLines(int, int, int);
};

#endif 