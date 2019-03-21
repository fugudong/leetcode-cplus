#pragma once
#include <iostream>  
#include <string>  
using namespace std;
class Base
{
public:
	Base(string s) : str_a(s) { }
	Base(const Base & that) { str_a = that.str_a; }
	void Print() const { cout << "In base: " << str_a << endl; }
protected:
	string str_a;
};
class Derived : public Base
{
public:
	Derived(string s1, string s2) : Base(s1), str_b(s2) { }  // 调用基类构造函数初始化
	void Print() const { cout << "In derived: " << str_a + " " + str_b << endl; }
protected:
	string str_b;
};
