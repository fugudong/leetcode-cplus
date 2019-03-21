#ifndef CIRCLE_H
#define CIRCLE_H

// TODO: ���Ҫ�ڴ˴�Ԥ����ı�ͷ


class Circle
{
public:
	Circle();
	~Circle();
	Circle(double r, double x, double y);
	void GetOrigin(double * x, double * y);
	void SetOrigin(double x, double y);
	double GetRadius();
	void SetRadius(double r);
	double GetPerimeter();
	double GetArea();
private:
	double r, x, y;
	double *p;
};


#endif //PCH_H