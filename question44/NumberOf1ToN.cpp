#include<iostream>
using namespace std;

int GetNumberDigits( int * n )			//得到n对应的数字位数 
{
	if( *n < 10 )
		return 1;
	else
		*n -= 1;
	int digits = 1, currentNum = 9;
	while( *n >= currentNum * digits )
	{
		*n -= currentNum * digits;
		digits++;
		currentNum *= 10;
	}
	return digits;
}

int BeginNum( int digits )				//返回最小的digits位数字 
{
	if( digits == 1 )
		return 0;
	int begin = 1;
	while( digits > 1 )
	{
		begin *= 10;
		digits--;
	}
	return begin;
}

int FindLocationInNumber( int number, int location )		//返回number中第location位对应的数字 
{
	while( location > 1 )
	{
		number /= 10;
		location--;
	}
	return number % 10;
}

int NumberOf1ToN( int n )
{
	if( n < 0 )
		throw exception();
	int digits = GetNumberDigits( &n );
	int number = n / digits + BeginNum( digits );
	int location = n % digits;
	return FindLocationInNumber( number, digits - location );
}

void Test( const char * str, int n, int ans )
{
	cout << str << ": ";
	try
	{
		if( NumberOf1ToN( n ) == ans )
			cout << "Passed!" << endl;
		else
			cout << "Failed!" << endl;
	}
	catch( const exception & )
	{
		cout << "Bad Input!" << endl;
	}
}

int main()
{
	Test( "test1", 1001, 7 );
	
	Test( "test2", 10, 1 );
	
	Test( "test3", -1, 0 );
	
	Test( "test4", 0, 0 );
	
	Test( "test5", 1, 1 );
	
	return 0;
}
