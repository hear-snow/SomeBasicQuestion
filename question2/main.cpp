#include "Singleton.h"
#include <iostream>
using namespace std;

void Test()
{
	cout << "test:创建两个Singleton实例" << endl;
	Singleton * p1 = Singleton::Instance();
	Singleton * p2 = Singleton::Instance();
	cout << "正常的输出: " << p1 << ' ' << p1 << endl;
	cout << "实际的输出: " << p1 << ' ' << p2 << endl;
}

int main()
{
	Test();
	
	return 0;
}
