#pragma once
#ifndef _BOARD
#define _BOARD



#define BLOCK_SIZE 40
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 10



class Board
{
	int boardArray[BOARD_HEIGHT][BOARD_WIDTH];

public:
	Board(void);
	void initBoard();
	int cellType(int, int);
	void draw();
	void changeCell(int, int, int);
	int deleteLines(int, int);
	void checkLines(int, int);
};

#endif 