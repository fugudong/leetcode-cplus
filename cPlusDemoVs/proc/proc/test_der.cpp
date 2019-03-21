#include "pch.h"
#include "base.h"

int main()
{
	Derived d1("Hello", "World");

	Base b1(d1);   // 拷贝构造，派生类至基类，仅复制基类部分
	d1.Print();  // Hello World
	b1.Print();  // Hello

	Base & b2 = d1;  // 引用，不调用拷贝构造函数，仅访问基类部分
	d1.Print();
	b2.Print();

	Base * b3 = &d1;  // 指针，不调用拷贝构造函数，仅引领基类部分
	d1.Print();
	b3->Print();
	return 1;
}
