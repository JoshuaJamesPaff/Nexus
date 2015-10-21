//#include "stdafx.h"
#include "Engine.h"
#include "Drawer.h"

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

bool Engine::cellFree(int x, int y){

	return (gameBoard->cellType(x,y) == 0);
	
}

void Engine::selectCell(int x, int y)
{

	//if first click
	if( (gameBoard->cellType(x,y) > 0) && (cellSelected == false))
	{
		cellSelected = true;
		selectedColor = gameBoard->cellType(x,y);
		//changes to selected picture
		gameBoard->changeCell(x, y);
		selectedCell[0] = x;
		selectedCell[1] = y;

		// second click to move
	}else if ((gameBoard->cellType(x,y) == 0) && (cellSelected == true))
	{

		changeCell(selectedCell[0], selectedCell[1], 0);
		changeCell(x, y, selectedColor);
		randCell();

		cellSelected = false;
	}
	
}

// overloades changecell function to change 1 cells color and update
void Engine::changeCell(int x, int y, int colour)
{
	gameBoard->changeCell(x, y, colour);	
	score = gameBoard->getCellsCleared();

}

//randomly generates coordinates and colors of cells
void Engine::randCell()
{
	int cell[3];
	
	
	System::Random^ random = gcnew System::Random((int)System::DateTime::Now.Ticks & 0x0000FFFF);

	for(int i = 0; i<3; i++){

		cell[0] = random->Next(9);
		cell[1] = random->Next(9);
		cell[2] = 1+(random->Next(6));
		gameBoard->changeCell(cell[0], cell[1], cell[2]);
		
	}
		
}





