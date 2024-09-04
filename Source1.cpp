#include "Header1.h"

int gI = 0;

int i = 7;

int& f(int i)
{
	static int j = i;
	j++;
	i = 7;
	return j;
	return gI;
}


