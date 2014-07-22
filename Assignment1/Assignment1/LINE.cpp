#include "LINE.h"



LINE::LINE(int x,int y,int x1,int y1,int r,int g,int b)
{
	
	lineBitmap = create_bitmap(360,360);
	clear_to_color(lineBitmap , makecol(255, 0, 255));
	line(lineBitmap,x,y,x1,y1,makecol(r,g,b));
}


LINE::LINE(void)
{
}


LINE::~LINE(void)
{
}
void LINE::draw(BITMAP * bb)
{
	rotate_sprite(bb,lineBitmap,50,50,0);
}
