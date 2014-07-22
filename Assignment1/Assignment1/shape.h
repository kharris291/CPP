#pragma once
#include <allegro.h>
class shape
{
public:
	shape(void);
	~shape(void);

	BITMAP *circleBitmap;
	BITMAP *lineBitmap;
	BITMAP *boxBitmap;
	int centre,x,y,x1,y1,r,g,b;
	
	virtual void draw(BITMAP *bb)=0;
	
};