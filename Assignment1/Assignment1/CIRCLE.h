#pragma once
#include "shape.h"
class CIRCLE :
	public shape
{
public:


	CIRCLE(int x,int y,int centre,int r,int g,int b);

	CIRCLE(void);
	~CIRCLE(void);

	


	void draw(BITMAP * bb);
};

