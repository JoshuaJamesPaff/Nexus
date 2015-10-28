
#include "Drawer.h"
using System::Drawing::Drawing2D::WrapMode;

void Drawer::init(Graphics^ f)
{
	formGraphics = f;
}

void Drawer::draw(Board& board)
{
	formGraphics->DrawRectangle(outline, Rectangle(0, 0, BLOCK_SIZE * BOARD_HEIGHT - 1, BLOCK_SIZE * BOARD_WIDTH - 1));
	for(int i = 0; i < BOARD_HEIGHT; i++)
	{
		for(int j = 0; j < BOARD_WIDTH; j++)
		{	
			TextureBrush^ texture = gcnew TextureBrush( images[board.cellType(i, j)], WrapMode::Tile );
			formGraphics->FillRectangle(texture, Rectangle( j * BLOCK_SIZE, i * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE));
			formGraphics->DrawRectangle(border, Rectangle( j * BLOCK_SIZE, i * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE));
			delete texture;
		}
	}

}

