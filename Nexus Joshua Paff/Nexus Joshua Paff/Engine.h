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
	inline bool isGameStarted(){ return gameStarted; };	
	void draw();	
	inline int getScore(){ return totalScore; };
	
};

#endif // end GAME def
