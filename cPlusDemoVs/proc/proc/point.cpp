
#include "pch.h"
#include "point.h"
#include <fstream>


// ¡°main.cpp¡±
int main()
{
	Point * pt1 = new Point2D(1, 2);
	Point * pt2 = new Point3D(1, 2, 3);
	ofstream ofs("~/data.txt");
	ofs << pt1;
	ofs << pt2;
	pt1->Print();
	pt2->Print();

	return 0;
}

