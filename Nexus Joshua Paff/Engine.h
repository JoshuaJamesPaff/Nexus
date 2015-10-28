#pragma once
#ifndef _ENGINE
#define _ENGINE

#include "Board.h"
#include <vector>

using namespace std;




class Engine
{
	
	Board *gameBoard;	
	int score;
	bool gameStarted;
	bool cellSelected;
	int selectedColor;
	int selectedCell[2];
	int destinationCell[2];
	bool pathfound;
	vector< vector<int> > cells;
	int counter;

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
	void scoreCells(int, int, int, int);
	bool findPath(int, int, int, int);
	
};

#endif 
