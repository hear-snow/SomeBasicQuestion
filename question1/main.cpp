#include "CMyString.h"
using namespace std;

void Test1()
{
	cout << "test1：将一个CMyString实例赋给另外一个实例" << endl;
	char * text = "hello world!";
	CMyString str1( text ), str2;
	cout << "正确的结果：" << str1 << endl;	
	str2 = str1;
	cout << "实际的结果：" << str2 << endl;
}

void Test2()
{
	cout << "test2：将一个CMyString实例赋给自己" << endl;
	char * text = "hello world!";
	CMyString str1( text );
	cout << "正确的结果：" << str1 << endl;	
	str1 = str1;
	cout << "实际的结果：" << str1 << endl;
}

void Test3()
{
	cout << "test3：连续赋值" << endl;
	char * text = "hello world!";
	CMyString str1( text ), str2, str3;
	cout << "正确的结果：" << str1 << ' ' << str1 << endl;	
	str3 = str2 = str1;
	cout << "实际的结果：" << str2 << ' ' << str3 << endl;
}

int main()
{
	Test1();
	Test2();
	Test3();
	
	return 0;
}
