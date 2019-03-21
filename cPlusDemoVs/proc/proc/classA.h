#pragma once
#include <iostream>
using namespace std;

class A
{
public:
	A() : _n(0), _p(NULL) { }
	explicit A(int n) : _n(n), _p(new int[n]) { }
	A(int n, int * p) : _n(n), _p(p) { }
	//A(const A & that) : _n(that._n), _p(that._p) { }
	//A & operator=(const A & that) { _n = that._n, _p = that._p; return *this; }
	A(const A & that);
	A(A &that);//左引用实现移动构造
	A(A && that);//右引用实现移动构造
	A & operator=(const A & that);
	A & operator=(A &that);//左引用实现移动赋值
	A & operator=(A && that);//右引用实现移动赋值
	virtual ~A() { if (_p) { delete[] _p, _p = NULL; } }
public:
	int & operator[](int i);
	const int & operator[](int i) const;
private:
	int _n;
	int * _p;
};
