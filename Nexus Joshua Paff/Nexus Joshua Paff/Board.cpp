#include "Board.h"
#include "Drawer.h"


Board::Board(void)
{
	initBoard();
}

void Board::initBoard()
{
	for(int i = 0; i < BOARD_HEIGHT; i++)
		for(int j = 0; j < BOARD_WIDTH; j++)
		{
			boardArray[i][j] = 0;
		}
}

int Board::cellType(int x, int y)
{
	return boardArray[x][y];
}

//draws board
void Board::draw()
{
	Drawer::draw(*this);
}

//changes color of induvidual cell
void Board::changeCell(int x, int y, int colour)
{
	boardArray[x][y] = colour;
	checkLines(x, y, colour);
}


void Board::checkLines(int x, int y, int colour){
	int totalCount =0;
	int Rcounter = 0;
	int Lcounter = 0;
	int Ucounter = 0;
	int Dcounter = 0;
	int RUcounter = 0;
	int LBcounter = 0;
	int RBcounter = 0;
	int LUcounter = 0;


	//x axis
	//left
	for(int i = 1; i <5 ; i++){
		if(boardArray[x][y+i] == colour){
			Lcounter++;
		}else{
			i=5;
		}
	}

	//right
	for(int i = 1; i <5 ; i++){
		if(boardArray[x][y-i] == colour){
			Rcounter++;
		}else{
			i=5;
		}
	}	
	
	if ((Rcounter + Lcounter) >= 4){

			for(int i = 0; i <= Lcounter; i++){
				boardArray[x][y+i] = 0;
				totalCount ++;
			}

			for(int i = 0; i <= Rcounter; i++){
				boardArray[x][y-i] = 0;
				totalCount ++;
			}
	
	}

	//y axis
	//up
	for(int i = 1; i <5 ; i++){
		if(boardArray[x+i][y] == colour){
			Ucounter++;
		}else{
			i=5;
		}
	}

	//down
	for(int i = 1; i <5 ; i++){
		if(boardArray[x-i][y] == colour){
			Dcounter++;
		}else{
			i=5;
		}
	}	

	if ((Dcounter + Ucounter) >= 4){

			for(int i = 0; i <= Ucounter; i++){
				boardArray[x+i][y] = 0;
				totalCount ++;
			}

			for(int i = 0; i <= Dcounter; i++){
				boardArray[x-i][y] = 0;
				totalCount ++;
			}
	
	}

	//da axis
	//left top
	for(int i = 1; i <5 ; i++){
		if(boardArray[x-i][y-i] == colour){
			LUcounter++;
		}else{
			i=5;
		}
	}

	//right bottom
	for(int i = 1; i <5 ; i++){
		if(boardArray[x+i][y+i] == colour){
			RBcounter++;
		}else{
			i=5;
		}
	}	
	
	if ((RBcounter + LUcounter) >= 4){ //if 5 in a row (0,1,2,3,4)

			for(int i = 0; i <= LUcounter; i++){
				boardArray[x-i][y-i] = 0;
				totalCount ++;
			}

			for(int i = 0; i <= RBcounter; i++){
				boardArray[x+i][y+i] = 0;
				totalCount ++;
			}
	
	}

	//db axis
	//right top
	for(int i = 1; i <5 ; i++){
		if(boardArray[x-i][y+i] == colour){
			RUcounter++;
		}else{
			i=5;
		}
	}

	//left bottom
	for(int i = 1; i <5 ; i++){
		if(boardArray[x+i][y-i] == colour){
			LBcounter++;
		}else{
			i=5;
		}
	}	
	
	if ((RUcounter + LBcounter) >= 4){

			for(int i = 0; i <= RUcounter; i++){
				boardArray[x-i][y+i] = 0;
				totalCount ++;
			}

			for(int i = 0; i <= LBcounter; i++){
				boardArray[x+i][y-i] = 0;
				totalCount ++;
			}
	
	}

	cellsCleared = totalCount;

}


