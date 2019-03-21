#include "pch.h"
#include "base.h"

int main()
{
	Derived d1("Hello", "World");

	Base b1(d1);   // �������죬�����������࣬�����ƻ��ಿ��
	d1.Print();  // Hello World
	b1.Print();  // Hello

	Base & b2 = d1;  // ���ã������ÿ������캯���������ʻ��ಿ��
	d1.Print();
	b2.Print();

	Base * b3 = &d1;  // ָ�룬�����ÿ������캯������������ಿ��
	d1.Print();
	b3->Print();
	return 1;
}
