#include<iostream>
using namespace std;

bool equal( double num1, double num2 )
{
	return ( num1 > num2 - 0.000001 && num1 < num2 + 0.000001 ) ? true : false;
}

double PowerProcess( double base, unsigned int exponent )
{
	if( exponent == 0 )
		return 0;
	if( exponent == 1 )
		return base;
	
	double answer = PowerProcess( base, exponent >> 1 );
	return ( exponent & 0x1 ) ? answer * answer * base : answer * answer;
}

double Power( double base, int exponent )
{
	if( equal( base, 0.0 ) && exponent <= 0 )
		throw "Bad Input!";
	
	unsigned int absExponent = exponent >= 0 ? exponent : -exponent;
	
	double answer = PowerProcess( base, absExponent );
	if( exponent < 0 )
		answer = 1.0 / answer;
	return answer;
} 

void Test1()
{
	cout << "test1: 功能测试" << endl;
	cout << "正常的结果: 11602.9" << endl; 
	double base = 6.5;
	int exponent = 5;
	try
	{
		double answer = Power( base, exponent );
		cout << "实际的结果: " << answer << endl; 
	}
	catch( const char * s )
	{
		cout << "实际的结果: " << s << endl; 
	}
	
}

void Test2()
{
	cout << "test2: 功能测试" << endl;
	cout << "正常的结果: 0.0625" << endl; 
	double base = 4;
	int exponent = -2;
	try
	{
		double answer = Power( base, exponent );
		cout << "实际的结果: " << answer << endl; 
	}
	catch( const char * s )
	{
		cout << "实际的结果: " << s << endl; 
	}
	
}

void Test3()
{
	cout << "test3: 负面测试" << endl;
	cout << "正常的结果: Bad Input!" << endl; 
	double base = 0;
	int exponent = -1;
	try
	{
		double answer = Power( base, exponent );
		cout << "实际的结果: " << answer << endl; 
	}
	catch( const char * s )
	{
		cout << "实际的结果: " << s << endl; 
	}
	
}

int main()
{
	Test1();
	Test2();
	Test3();
	
	return 0;
}
