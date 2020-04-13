#include<iostream>
using namespace std;

bool scanUnsignedInteger( const char ** str )
{
	const char * temp = *str;
	while( **str != '\0' && **str >= '0' && **str <= '9' )
		++( *str );
	return *str > temp;
}

bool scanInteger( const char ** str )
{
	if( **str == '+' || **str == '-' )
		++( *str );
	return scanUnsignedInteger( str );
}

bool StringIsNumber( const char * str )
{
	if( str == nullptr )
		return false;
	bool flag = scanInteger( &str );
	if( *str == '.' )
	{
		str++;
		flag = scanUnsignedInteger( &str ) || flag;
	}
	if( *str == 'e' || *str == 'E' )
	{
		str++;
		flag = scanInteger( &str ) && flag;
	}
	return flag && ( *str == '\0' );
}

void Test1()
{
	cout << "test1: 功能测试" << endl;
	char str[] = "123.45e+6";
	cout << "正确的输出: 可以表示为数字" << endl;
	if( StringIsNumber( str ) )
		cout << "实际的输出: 可以表示为数字" << endl;
	else
		cout << "实际的输出: 不可以表示为数字" << endl; 
} 

void Test2()
{
	cout << "test2: 功能测试" << endl;
	char str[] = "123.e0.6";
	cout << "正确的输出: 不可以表示为数字" << endl;
	if( StringIsNumber( str ) )
		cout << "实际的输出: 可以表示为数字" << endl;
	else
		cout << "实际的输出: 不可以表示为数字" << endl; 
}

void Test3()
{
	cout << "test3: 负面测试" << endl;
	char * str = nullptr;
	cout << "正确的输出: 不可以表示为数字" << endl;
	if( StringIsNumber( str ) )
		cout << "实际的输出: 可以表示为数字" << endl;
	else
		cout << "实际的输出: 不可以表示为数字" << endl; 
}

int main()
{
	Test1();
	Test2();
	Test3();
	
	return 0;
}
