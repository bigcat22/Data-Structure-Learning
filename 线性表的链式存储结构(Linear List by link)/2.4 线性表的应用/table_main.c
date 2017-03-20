// gcc with func.c
#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"

void main ()
{
	HList * h1, *h2, *h;
	printf ("表1：\n");
	CreateTable (h1);
	printf ("表2：\n");
	CreateTable (h2);
	LinkTable (h1, h2, h);
	printf ("连接结果表：\n");
	DispTable (h);
	DestoryTable (h1);
	DestoryTable (h2);
	DestoryTable (h);
}
