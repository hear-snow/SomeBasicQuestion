#include<iostream>
using namespace std;

long long Fibonacci( int n )
{
	if( n < 0 )
		throw "bad input";
	else if( n == 0 )
		return 0;
	else if( n == 1 )
		return 1;
	else
	{
		long long Sum = 0;
		long long LastSum = 1;
		long long LastLastSum = 0;
		for( int i = 2; i <= n; i++ )
		{
			Sum = LastSum + LastLastSum;
			LastLastSum = LastSum;
			LastSum = Sum;
		}
		return Sum;
	}
}

void Test1()
{
	int n = 50;
	cout << "test1: ��쳲��������еĵ�n��" << endl;
	cout << "���������: 12586269025" << endl; 
	cout << "ʵ�ʵ����: ";
	try
	{
		long long sum = Fibonacci( n );
		cout << sum << endl;
	}
	catch( const char * s )
	{
		cout << s << endl;
	}
}

void Test2()
{
	int n = -1;
	cout << "test2: һ�����õ�����" << endl;
	cout << "���������: bad input" << endl; 
	cout << "ʵ�ʵ����: ";
	try
	{
		long long sum = Fibonacci( n );
		cout << sum << endl;
	}
	catch( const char * s )
	{
		cout << s << endl;
	}
}

int main()
{
	Test1();
	Test2();
	
	return 0;
}
