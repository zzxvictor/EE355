#include "MyHeader.h"

Point::Point()
{
	x = 0;
	y = 0;
}

void Point::setCoordinate(int X, int Y)
{
	x = X;
	y = Y;
}

int Point::getX()
{
	return x;

}

int Point::getY()
{
	return y;
}
