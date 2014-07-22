#pragma once
#include "shape.h"
class LINE :
	public shape
{
public:
	LINE(void);
	~LINE(void);


	LINE(int x,int y,int x1,int y1,int r,int g,int b);
	void draw(BITMAP * bb);
};

