#pragma once
#ifndef _ENGINE
#define _ENGINE

#include "Board.h"



class Engine
{
	
	Board *gameBoard;	
	int score;
	bool gameStarted;
	bool cellSelected;
	int selectedColor;
	int selectedCell[2];

public:
	
	Engine(void);
	void start(void);	
	void draw();
	void changeCell(int, int, int);
	void randCell();
	inline int getScore() { return score; }
	inline bool isCellSelected() { return cellSelected; }
	inline bool gameStart(){ return gameStarted; }
	bool cellFree(int, int);
	void selectCell(int, int);
	inline int getSelectedColor() { return selectedColor; }
	
	
};

#endif 
