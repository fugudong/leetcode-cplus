//#include "stdafx.h"
#include "circle.h"

const double pi = 3.141592653589793;

Circle::Circle()
{
	this->r = 4.0;
	this->x = 0.0;
	this->y = 0.0;
	p = new double;
	*p = 5.0;
}

Circle::~Circle()
{
	delete p;
	p = 0;
}

Circle::Circle(double r, double x, double y)
{
	this->r = r;
	this->x = x;
	this->y = y;
	p = new double;
	*p = r;
}

void Circle::GetOrigin(double * x, double * y)
{
	*x = this->x;
	*y = this->y;
}

void Circle::SetOrigin(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Circle::GetRadius()
{
	*p = 6.0;
	return *p;
}

void Circle::SetRadius(double r)
{
	this->r = r;
}

double Circle::GetPerimeter()
{
	return 2 * pi * r;
}

double Circle::GetArea()
{
	return pi * r * r;
}
#pragma once