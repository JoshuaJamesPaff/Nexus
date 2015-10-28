#pragma once
#ifndef _BOARD
#define _BOARD



#define BLOCK_SIZE 40
#define BOARD_WIDTH 7
#define BOARD_HEIGHT 7



class Board
{
	int boardArray[BOARD_WIDTH][BOARD_HEIGHT];
	int cellsCleared;
	
	

public:
	Board(void);
	void initBoard();
	int cellType(int, int);
	void draw();
	inline int getCellsCleared() { return cellsCleared; }
	void changeCell(int, int);
	void changeCell(int, int, int);
	void checkLines(int, int, int);
};

#endif 