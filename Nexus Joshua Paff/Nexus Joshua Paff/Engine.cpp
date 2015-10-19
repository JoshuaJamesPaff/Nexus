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
	gameBoard->loadBoard(); // game board	
	totalScore = 0;
	gameStarted = true;
	
}

//moves the shape then checks for collisions. if collided it locks it in place and sends a new shape
//bool Engine::moveShape(char x, char y){

//	activeShape->move(x, y);
//	if(!isValidMove())
//	{
//		activeShape->move(-1 * x, -1 * y);
//		
//		if(x == 0)
//		{
//			gamePanel->lockShape(*activeShape); //locks shape 
//			totalScore += 5 * gamePanel->clearLines(activeShape->getY()); //clears line and updates score
//			delete activeShape;
//			nextShape();
//		}
//
//		return false;
//	}
//
//	return true;
//}




//tells the game board to draw itself and then the current shape to draw itself on top
void Engine::draw()
{
	gameBoard->draw();	
	
}
