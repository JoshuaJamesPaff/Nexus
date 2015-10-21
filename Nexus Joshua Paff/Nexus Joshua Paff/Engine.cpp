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
}


//tells the game board to draw itself 
void Engine::draw()
{
	gameBoard->draw();	
	
}

void Engine::changeCell(int x, int y, int colour)
{
	gameBoard->changeCell(x, y, colour);	
	

}

void Engine::randCell()
{
	int x[3];
	int y[3];
	int c[3];
	System::Random^ random = gcnew System::Random((int)System::DateTime::Now.Ticks & 0x0000FFFF);
	for(int i = 0; i<3; i++){
		x[i] = random->Next(9);
		y[i] = random->Next(9);
		c[i] = 1+(random->Next(6));
		
	}
	gameBoard->changeCell(x[0], y[0], c[0]);	
	gameBoard->changeCell(x[1], y[1], c[1]);	
	gameBoard->changeCell(x[2], y[2], c[2]);	
}





