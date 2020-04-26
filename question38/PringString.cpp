#include<iostream>
using namespace std;

void PrintStringProcess( char * str, char * strBegin )
{
	if( *strBegin == '\0' )
	{
		cout << str << endl;
		return;			
	}
	for( char * c = strBegin; *c != '\0'; c++ )
	{
		char tmp = *c;				//��һ���ַ��������ַ��ֱ𽻻�
		*c = *strBegin;
		*strBegin = tmp;
		
		PrintStringProcess( str, strBegin + 1 );
		
		tmp = *c;					//ÿһ�ν�������Ҫ��ԭstr���ܽ�����һ�ν��� 
		*c = *strBegin;
		*strBegin = tmp;
	}
}

void PrintString( char * str )
{
	if( str == nullptr )
		return;
	PrintStringProcess( str, str );
}

void Test1()
{
	cout << "test1: ���ܲ���" << endl;
	cout << "��ȷ�����: " << endl;
	cout << "abc" << endl;
	cout << "acb" << endl;
	cout << "bac" << endl;
	cout << "bca" << endl;
	cout << "cba" << endl;
	cout << "cab" << endl;
	cout << "ʵ�ʵ����: " << endl;
	char str[] = "abc";
	PrintString( str );
}

void Test2()
{
	cout << "test2: �������" << endl;
	cout << "��ȷ�����: " << endl;
	cout << "ʵ�ʵ����: " << endl;
	char * str = nullptr;
	PrintString( str );
}

int main()
{
	Test1();
	Test2();
	
	return 0;
}
