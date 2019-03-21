#include "pch.h"
#include "classA.h"

int & A::operator[](int i)
{
	if (i < 0 || i >= 4)
		throw std::out_of_range("Out of range when trying to access the object...");
	return _p[i];
}

const int & A::operator[](int i) const
{
	if (i < 0 || i >= 4)
		throw std::out_of_range("Out of range when trying to access the object...");
	return _p[i];
}

A::A(const A &that)
{
	this->_n = that._n;
	_p = new int[_n];
	for (int i = 0; i < _n; i++)
	{
		_p[i] = that._p[i];
	}
}

A::A(A & that)
{
	_n = that._n, _p = that._p, that._n = 0, that._p = nullptr;
}

A::A(A &&that)//移动构造
{
	_n = that._n, _p = that._p;
	that._n = 0, that._p = nullptr;
}

A &A::operator=(const A& that)
{
	this->_n = that._n;
	if (_p)
		delete[] _p;
	_p = new int[_n];
	for (int i = 0; i < _n; i++)
		_p[i] = that._p[i];
	return *this;
}

A & A::operator=(A & that)
{
	_n = that._n, _p = that._p, that._n = 0, that._p = nullptr;
	return *this;
}

A & A::operator=(A && that)//移动赋值
{
	if (_p) delete[] _p;

	_n = that._n, _p = that._p;
	that._n = 0, that._p = nullptr;

	return *this;
}


int main()
{
	A a(4), b(4);
	for (int i = 0; i < 4; i++)
		a[i] = i + 1;
	std::cout << "Before object assignment:" << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	b = a;
	std::cout << "After object assignment:" << std::endl;
	b[3] = 10;
	for (int i = 0; i < 4; i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	A c(a);//拷贝构造
	A g(c);
	//g = c;//普通赋值
	for (int i = 0; i < 4; i++)
		std::cout << g[i] << " ";
	std::cout << std::endl;
	A d(static_cast<A &&>(g));
	A e;
	e = static_cast<A &&>(d);
	A f;
	f = static_cast<A &>(e);
	for (int i = 0; i < 4; i++)
		std::cout << f[i] << " ";
	return 0;    //
}
