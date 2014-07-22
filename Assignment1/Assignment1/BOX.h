#pragma once
#include "shape.h"
class BOX :
	public shape
{
public:
	BOX(int x,int y,int x1,int y1,int r,int g,int b);

	BOX(void);
	~BOX(void);
	

	void draw(BITMAP * bb);
};

