//#include "stdafx.h"
#include "Engine.h"
#include "Drawer.h"
#include <vector>

using namespace std;

//constructor
Engine::Engine(void)
{
	gameBoard = new Board();
	
}

//initialises values and starts the game
void Engine::start(void)
{
	gameBoard->initBoard(); // game board
	gameStarted = true;
	
}



//tells the game board to draw itself 
void Engine::draw()
{
	gameBoard->draw();	
	
}
//returns true if cell is empty
bool Engine::cellFree(int x, int y){

	return (gameBoard->cellType(x,y) == 0);
	
}

//selects the cell to move and then moves it to a free space
void Engine::selectCell(int x, int y)
{
	destinationCell[0] = x;
	destinationCell[1] = y;

	//if first click then change it to a grey color
	if( (gameBoard->cellType(x,y) > 0) && (cellSelected == false))
	{
		cellSelected = true;
		selectedColor = gameBoard->cellType(x,y);
		//changes to selected picture
		gameBoard->changeCell(x, y);
		selectedCell[0] = x;
		selectedCell[1] = y;

		// if second click then check pathfinding and if theres a path then swap cells cell 
	}else if ((gameBoard->cellType(x,y) == 0) && (cellSelected == true))
	{
		findPath(selectedCell[0], selectedCell[1], destinationCell[0], destinationCell[1]);

		if(pathfound == true){

		changeCell(selectedCell[0], selectedCell[1], 0);
		changeCell(x, y, selectedColor);
		randCell();

		cellSelected = false;
		}
		
		
	}
	
}

// overloades changecell function to change 1 cells color and update
void Engine::changeCell(int x, int y, int colour)
{
	gameBoard->changeCell(x, y, colour);	
	score = gameBoard->getCellsCleared();

}


//scores cells and checks for freecells in the vicinity
void Engine::scoreCells(int ax, int ay, int bx, int by){
	
	// adds 4 xy coordinates and their scores into a vector of vectors
	//right
	if(gameBoard->cellType(ax+1, ay) == 0){
		if(ax+1 == bx && ay ==by){
			pathfound = true;
		}else{
		vector<int> row;
		row.push_back(ax+1);
		row.push_back(ay);
		//scoring
		int tempx = row[0] - bx;
		int tempy = row[1] - by;
		if(tempx <0) tempx *= -1;
		if(tempy <0) tempy *= -1;
		int score = tempx + tempy;
		row.push_back(score);

		cells.push_back(row);	
		}
	}
	//left
	if(gameBoard->cellType(ax-1, ay) == 0){
		if(ax-1 == bx && ay ==by){
			pathfound = true;
		}else{
		vector<int> row;
		row.push_back(ax-1);
		row.push_back(ay);
		//scoring
		int tempx = row[0] - bx;
		int tempy = row[1] - by;
		if(tempx <0) tempx *= -1;
		if(tempy <0) tempy *= -1;
		int score = tempx + tempy;
		row.push_back(score);
		
		cells.push_back(row);
		}
		
			
	}
	//below
	if(gameBoard->cellType(ax, ay+1) == 0){
		if(ax == bx && ay+1 ==by){
			pathfound = true;
		}else{
		vector<int> row;
		row.push_back(ax);
		row.push_back(ay+1);
		//scoring
		int tempx = row[0] - bx;
		int tempy = row[1] - by;
		if(tempx <0) tempx *= -1;
		if(tempy <0) tempy *= -1;
		int score = tempx + tempy;
		row.push_back(score);
		
		cells.push_back(row);
		
		}
		
	}
	//above
	if(gameBoard->cellType(ax, ay-1) == 0){
		if(ax == bx && ay-1 ==by){
			pathfound = true;
		}else{
		vector<int> row;
		row.push_back(ax);
		row.push_back(ay-1);
		//scoring
		int tempx = row[0] - bx;
		int tempy = row[1] - by;
		if(tempx <0) tempx *= -1;
		if(tempy <0) tempy *= -1;
		int score = tempx + tempy;
		row.push_back(score);
		
		cells.push_back(row);
		}
	}
}

// calls the scoreCells method on every free cell it finds and flips a bool if it finds the destination cell
bool Engine::findPath(int ax, int ay, int bx, int by){
	pathfound = false;

	//scores the original cell
	scoreCells(ax, ay, bx, by);

	
	
		for(int i = 0; i < cells.size(); i++){
			//
			if(cells.size() < 10000){

			if(!pathfound) scoreCells(cells[i][0], cells[i][1], bx, by);
			}
			
		}
	

	cells.clear();
	return pathfound;

}


//randomly generates coordinates and colors of cells
void Engine::randCell()
{
	pathfound = false;
	int cell[3];
	
	
	System::Random^ random = gcnew System::Random((int)System::DateTime::Now.Ticks & 0x0000FFFF);

	for(int i = 0; i<3; i++){

		cell[0] = random->Next(9);
		cell[1] = random->Next(9);
		cell[2] = 1+(random->Next(6));
		gameBoard->changeCell(cell[0], cell[1], cell[2]);
		
	}
		
}





