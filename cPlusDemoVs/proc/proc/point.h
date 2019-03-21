#pragma once
#include <iostream>
using namespace std;

class Point
{
public:
	Point() { }
	virtual void Print() const = 0;
	//  virtual ~Point();
};

class Point2D : virtual public Point
{
public:
	Point2D(int x = 0, int y = 0) : _x(x), _y(y) { }
	Point2D(const Point2D& pt2d) : _x(pt2d._x), _y(pt2d._y) { }
	int GetX() const { return _x; }
	void SetX(int x) { _x = x; }
	int GetY() const { return _y; }
	void SetY(int y) { _y = y; }
	friend ostream & operator<<(ostream & os, const Point2D & pt);
	friend istream & operator>>(istream & is, Point2D & pt);
	virtual void Print() const { cout << "( " << _x << ", " << _y << " )"; }
protected:
	int _x, _y;
};

class Point3D : virtual public Point2D
{
public:
	Point3D(int x = 0, int y = 0, int z = 0) : Point2D(x, y), _z(z) { }
	Point3D(const Point3D& pt3d) : Point2D(pt3d._x, pt3d._y), _z(pt3d._z) {  }
	int GetZ() const { return _z; }
	void SetZ(int z) { _z = z; }
	virtual void Print() const {
		cout << "( " << _x << ", " << _y << ", " << _z << " )";
	}
	friend ostream & operator<<(ostream & os, const Point3D & pt);
	friend istream & operator>>(istream & is, Point3D & pt);
protected:
	int _z;
};

ostream & operator<<(ostream & os, const Point2D & pt)
{
	os << '(' << pt._x << ',' << pt._y << ')';
	return os;
}

// 逐字符分析，确保文件非致命改动不影响数据读取
istream & operator>>(istream & is, Point2D & pt)
{
	char _c;    int _a[2] = { 0, 0 }, _i = 0;    bool _started = false;
	_c = is.get();
	while (_c != '\n') {
		if (_c == '(') { _started = true; }
		else if (isdigit(_c)) { if (_started)    _a[_i] = _a[_i] * 10 + _c - 48; }
		else if (_c == ',') { _i++; }
		else if (_c == ')') { _started = false;   break; }
		_c = is.get();
	}
	pt._x = _a[0], pt._y = _a[1];    return is;
}

ostream & operator<<(ostream & os, const Point3D & pt)
{
	os << '(' << pt._x << ',' << pt._y << ',' << pt._z << ')';
	return os;
}
// 逐字符分析，确保文件非致命改动不影响数据读取
istream & operator>>(istream & is, Point3D & pt)
{
	char _c;    int _a[3] = { 0, 0, 0 }, _i = 0;    bool _started = false;
	_c = is.get();
	while (_c != '\n') {
		if (_c == '(') { _started = true; }
		else if (isdigit(_c)) { if (_started)    _a[_i] = _a[_i] * 10 + _c - 48; }
		else if (_c == ',') { _i++; }
		else if (_c == ')') { _started = false;    break; }
		_c = is.get();
	}
	pt._x = _a[0], pt._y = _a[1], pt._z = _a[2];    return is;
}
