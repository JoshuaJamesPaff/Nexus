//#include "stdafx.h"
#include "Drawer.h"
#include <iostream>

using namespace std;

void Drawer::init(Graphics^ f)
{
	formGraphics = f; 
	myBrush = gcnew SolidBrush(Color::Gray); // box color
	border = gcnew Pen(Color::Black);				// box outline
}



//takes a board as a parameter and draws it
void Drawer::draw(Board &b)
{
	for(char i = 0; i < BOARD_HEIGHT; i++)
	{	
		for(char j = 0; j < BOARD_WIDTH; j++)
		{
			
				formGraphics->FillRectangle(myBrush, Rectangle(j * BLOCK_SIZE, i * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE));
				formGraphics->DrawRectangle(border, Rectangle(j * BLOCK_SIZE, i * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE));
			
		}
	}
}


// checks which cells are which (empty/selected/red/blue/green/yellow/teal/purple)
char Board::cellType(int x, int y)
{
	if(y >= 0 && y < BOARD_WIDTH && x >= 0 && x < BOARD_HEIGHT)
		return board[x][y];
	else
		return -1; 
}
//compares two cells and returns true of they are the same
bool Board::compareCells(int ax, int ay, int bx, int by)
{
	return (cellType(ax, ay) == cellType(bx, by));
}


// checks for 5 of the same type in a row horizontally and vertically
int Board::checkLines()
{
	// counts amount of same colors in a row
	int sameCounter = 0;
	bool isSame = false;

	//saves locations of cells that are in a row
	int sameLocations[5][2] ;	
	

	//exit loop after finding 5 in a row (less than 4 because it starts checking at the second slot in the array
	while(sameCounter <4)
	{
		for(int i = 0; i < BOARD_HEIGHT; i++)
		{
			//starts at 1 so it doesnt compare the start cell with nothing
			for(j = 1; j < BOARD_WIDTH; j++)
			{		
				isSame = compareCells(i, j, i , j-1);
				if (isSame == true){
					sameLocations[sameCounter][0] = i;
					sameLocations[sameCounter][1] = j-1;
					sameCounter++;

				}
			}
				
		}		
			 
	}
}
