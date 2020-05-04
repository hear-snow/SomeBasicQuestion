#include<iostream>
using namespace std;

void FindNumbersWithSum( int * data, int length, int target, int & num1, int & num2 )
{
	if( data == nullptr || length < 2 )
		throw exception();
	while( num1 < num2 )
	{
		int Sum = data[ num1 ] + data[ num2 ];
		if( Sum == target )
			return;
		else if( Sum < target )
			num1++;
		else
			num2--;
	}
}

void Test( const char * str, int * data, int length, int target, int * ans )
{
	cout << str << ": ";
	int num1 = 0, num2 = length - 1;
	try
	{
		FindNumbersWithSum( data, length, target, num1, num2 );
		if( ( data[ num1 ] == ans[ 0 ] ) && ( data[ num2 ] == ans[ 1 ] ) )
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
	int num_1[] = { 1, 2, 4, 7, 11, 15 };
	int ans_1[] = { 4, 11 };
	int target = 15;
	Test( "test1", num_1, sizeof( num_1 ) / sizeof( int ), target, ans_1 );
	
	int ans_2[] = { 0, 0 };
	target = 0;
	Test( "test2", nullptr, 0, target, ans_2 );
	
	return 0;
} 
