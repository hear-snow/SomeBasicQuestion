#include<iostream>
using namespace std;

unsigned int FindFirstBitIs1( int num )
{
	unsigned int index = 0;
	while( ( ( num & 1 ) == 0 ) && ( index < 8 * sizeof( int ) ) )
	{
		index++;
		num = num >> 1;
	}
	return index;
}

bool FindBitIs1( int num, int index )
{
	num = num >> index;
	return ( num & 1 );
}

void FindNumsAppearOnce( int * data, int length, int & num1, int & num2 )
{
	if( data == nullptr || length <= 0 )
		throw exception();
	int resultAfterOR = 0;
	for( int i = 0; i < length; i++ )
		resultAfterOR ^= data[ i ];
	unsigned int index = FindFirstBitIs1( resultAfterOR );
	num1 = num2 = 0;
	for( int i = 0; i < length; i++ )
	{
		if( FindBitIs1( data[ i ], index ) )
			num1 ^= data[ i ];
		else
			num2 ^= data[ i ];
	}
}

void Test( const char * str, int * num, int length, int ans1, int ans2 )
{
	cout << str << ": ";
	int num1, num2;
	try
	{
		FindNumsAppearOnce( num, length, num1, num2 );
		if( ( num1 == ans1 && num2 == ans2 ) || ( num1 == ans2 && num2 == ans1 ) )
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
	int num_1[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	int ans1 = 6, ans2 = 4;
	Test( "test1", num_1, sizeof( num_1 ) / sizeof( int ), ans1, ans2 );
	
	int num_2[] = { 2, 4, 3, 4, 3, 2, 5, 5 };
	ans1 = 0;
	ans2 = 0;
	Test( "test2", num_2, sizeof( num_2 ) / sizeof( int ), ans1, ans2 );
	
	Test( "test3", nullptr, 0, ans1, ans2 );
	
	return 0;
}
