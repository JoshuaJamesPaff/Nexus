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



