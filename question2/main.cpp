#include "Singleton.h"
#include <iostream>
using namespace std;

void Test()
{
	cout << "test:��������Singletonʵ��" << endl;
	Singleton * p1 = Singleton::Instance();
	Singleton * p2 = Singleton::Instance();
	cout << "���������: " << p1 << ' ' << p1 << endl;
	cout << "ʵ�ʵ����: " << p1 << ' ' << p2 << endl;
}

int main()
{
	Test();
	
	return 0;
}
