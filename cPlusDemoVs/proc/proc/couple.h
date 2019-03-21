#pragma once
#include <iostream>
using namespace std;

class Couple
{
public:
	Couple(int a = 0, int b = 0) : _a(a), _b(b) {
		_c[0] = 10;
		_c[1] = 2;
	}
	friend Couple operator+(const Couple & c1, const Couple & c2);
	friend Couple operator*(const Couple & c1, const Couple & c2);
	friend bool operator==(const Couple & c1, const Couple & c2);
	friend bool operator!=(const Couple & c1, const Couple & c2);
	friend ostream & operator<<(ostream &os, const Couple &c);
	friend istream & operator>>(istream &is, Couple &c);
	Couple &operator +=(const Couple &c);
	Couple &operator *=(const Couple &c);
	Couple &operator *=(const int & k);
	Couple &operator =(const Couple& c);
	Couple &operator ++();	//  前缀递增
	Couple operator ++(int);	//  后缀递增
	int & operator[](int index);
	const int & operator[](int index) const;
	int Get_a() const;
private:
	int _a, _b;
	int _c[2];
};
