#include "BOX.h"


BOX::BOX(int x,int y,int x1,int y1,int r,int g,int b)
{
	
	boxBitmap = create_bitmap(400,400);
	clear_to_color(boxBitmap, makecol(255, 0, 255));

	rect(boxBitmap,x,y,x1,y1,makecol(r,g,b));
}


BOX::BOX(void)
{
}


BOX::~BOX(void)
{

}

void BOX::draw(BITMAP * bb)
{
	rotate_sprite(bb, boxBitmap, 50, 50, 0);
}

