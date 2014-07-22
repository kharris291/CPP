#include "CIRCLE.h"


CIRCLE::CIRCLE(int x,int y,int centre,int r,int g,int b)
{
	
	circleBitmap = create_bitmap(300,150);
	clear_to_color(circleBitmap , makecol(255, 0, 255));
	

	circle(circleBitmap,x,y,centre,makecol(r,g,b));
}

CIRCLE::CIRCLE(void)
{
	
}


CIRCLE::~CIRCLE(void)
{
}

void CIRCLE::draw(BITMAP * bb)
{
	rotate_sprite(bb,circleBitmap,50,50,0);
}