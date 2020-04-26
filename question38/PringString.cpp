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
		char tmp = *c;				//第一个字符与后面的字符分别交换
		*c = *strBegin;
		*strBegin = tmp;
		
		PrintStringProcess( str, strBegin + 1 );
		
		tmp = *c;					//每一次交换后需要还原str才能进行下一次交换 
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
	cout << "test1: 功能测试" << endl;
	cout << "正确的输出: " << endl;
	cout << "abc" << endl;
	cout << "acb" << endl;
	cout << "bac" << endl;
	cout << "bca" << endl;
	cout << "cba" << endl;
	cout << "cab" << endl;
	cout << "实际的输出: " << endl;
	char str[] = "abc";
	PrintString( str );
}

void Test2()
{
	cout << "test2: 负面测试" << endl;
	cout << "正确的输出: " << endl;
	cout << "实际的输出: " << endl;
	char * str = nullptr;
	PrintString( str );
}

int main()
{
	Test1();
	Test2();
	
	return 0;
}
