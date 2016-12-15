// Week5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Genetics.h"
#include <cstdio>


int main()
{
	Genetics g = Genetics();
	g.printGeneration();
	//g.reproduce(g.getFittest());
	//g.printGeneration();
	g.combine(1234567, 7654321, 4);
	std::getchar();
    return 0;
}

