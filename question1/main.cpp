#include "CMyString.h"
using namespace std;

void Test1()
{
	cout << "test1����һ��CMyStringʵ����������һ��ʵ��" << endl;
	char * text = "hello world!";
	CMyString str1( text ), str2;
	cout << "��ȷ�Ľ����" << str1 << endl;	
	str2 = str1;
	cout << "ʵ�ʵĽ����" << str2 << endl;
}

void Test2()
{
	cout << "test2����һ��CMyStringʵ�������Լ�" << endl;
	char * text = "hello world!";
	CMyString str1( text );
	cout << "��ȷ�Ľ����" << str1 << endl;	
	str1 = str1;
	cout << "ʵ�ʵĽ����" << str1 << endl;
}

void Test3()
{
	cout << "test3��������ֵ" << endl;
	char * text = "hello world!";
	CMyString str1( text ), str2, str3;
	cout << "��ȷ�Ľ����" << str1 << ' ' << str1 << endl;	
	str3 = str2 = str1;
	cout << "ʵ�ʵĽ����" << str2 << ' ' << str3 << endl;
}

int main()
{
	Test1();
	Test2();
	Test3();
	
	return 0;
}
