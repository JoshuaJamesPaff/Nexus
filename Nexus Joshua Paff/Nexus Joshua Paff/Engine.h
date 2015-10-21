#pragma once
#ifndef _ENGINE
#define _ENGINE

#include "Board.h"



class Engine
{
	
	Board *gameBoard;	
	int score;
	bool started;	
public:
	
	Engine(void);
	void start(void);	
	void draw();
	void changeCell(int, int, int);
	void randCell();
	inline int getScore() { return score; }
	inline bool gameStarted(){ return started; }
	
};

#endif 
