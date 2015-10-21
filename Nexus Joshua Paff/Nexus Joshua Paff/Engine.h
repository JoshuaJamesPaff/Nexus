#pragma once
#ifndef _ENGINE
#define _ENGINE

#include "Board.h"



class Engine
{
	
	Board *gameBoard;	
	int totalScore;
	bool gameStarted;	
public:
	
	Engine(void);
	void start(void);	
	void draw();
	void changeCell(int, int, int);
	void randCell();
	
};

#endif 
