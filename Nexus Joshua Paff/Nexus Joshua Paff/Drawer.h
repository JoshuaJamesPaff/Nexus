#pragma once
#ifndef _DRAWER
#define _DRAWER
#include "Board.h"



using namespace System::Drawing;
ref class Drawer
{
	static SolidBrush^ myBrush;
	static Pen^ border;
	static Graphics^ formGraphics;
public:
	static void init(Graphics^ f);	
	static void draw(Board&);
	
};


#endif
