#include "pch.h"
#include "couple.h"


Couple operator+(const Couple & c1, const Couple & c2)
{
	Couple _t(c1._a + c2._a, c1._b + c2._b);
	return _t;
}
Couple operator*(const Couple & c1, const Couple & c2)
{
	Couple _t(c1._a * c2._a, c1._b * c2._b);
	return _t;
}

int Couple::Get_a() const
{
	return _a;
}

bool operator==(const Couple & c1, const Couple & c2)
{
	return (c1._a == c2._a) && (c1._b == c2._b);
}
bool operator!=(const Couple & c1, const Couple & c2)
{
	return (c1._a != c2._a) || (c1._b != c2._b);
}

int & Couple::operator[](int index)
{
	cout << index<<endl;
	if (index < 0 || index > 1)
		throw std::out_of_range("Index is out of range!");
	return _c[index];
}

const int & Couple::operator[](int index) const
{
	if (index < 0 || index > 1)
		throw std::out_of_range("Const Index is out of range!");
	return _c[index];
}

Couple &Couple::operator=(const Couple& c)
{
	if (*this == c)
		return *this;
	_a = c._a, _b = c._b;

	return *this;
}

ostream & operator<<(ostream &os, const Couple &c)
{
	os << "(" << c._a << "." << c._b <<"."<<c[0]<<")" <<endl;
	return os;
}

istream & operator>>(istream &is, Couple &c)
{
	is >> c._a >> c._b>>c[0];
	return is;
}

Couple & Couple::operator+=(const Couple & c)
{
	_a += c._a, _b += c._b;
	return *this;
}

Couple & Couple::operator*=(const Couple & c)
{
	_a *= c._a, _b *= c._b;
	return *this;
}

Couple & Couple::operator*=(const int & k)
{
	_a *= k, _b *= k;
	return *this;
}

Couple Couple::operator++(int t)
{
	Couple _t(*this);
	_a++, _b++;
	return _t;
}

int main()
{
	float mpu[9] = { 1.0f, 1.0f, 28.0f, -2.2f, -1.0f, -85.3f, 0.0f, -0.0f, 1.0f };
	Couple a(1, 2), b(3, 4), c, d;
	c = a + b;	// 等价于 c = a.operator+(b)  ==> c( 4, 6 )
	cout << c.Get_a()<< endl;
	d = a + b + c;	// 等价于 d = a.operator+(b).operator+(c)  ==> d( 8, 12 )
	c = a * b;	// 等价于 c = a.operator*(b)  ==> c( 3, 8 )
	cout << c.Get_a() << endl;

	if (a == b) {
		cout << "a==b" << endl;
	}
	else{
		cout << "a!=b" << endl;
	}

	cout << b[1] << endl;

	cout << a << endl;
	a++;
	cout << a << endl;
	return 0;
}
