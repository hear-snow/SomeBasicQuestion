#include<iostream>
using namespace std;

int FindNumberAppearOnce2( int * num, int length )
{
	if( num == nullptr || length <= 0 )
		throw exception();
	int BitNum[ 8 * sizeof( int ) ] = { 0 };
	int BitNumLength = sizeof( BitNum ) / sizeof( int );
	for( int i = 0; i < length; i++ )
		for( int j = BitNumLength - 1; j >= 0; j-- )
			BitNum[ j ] += ( num[ i ] >> ( BitNumLength - j - 1 ) ) & 1;
	int result = 0;
	for( int j = 0; j < BitNumLength; j++ )
		if( BitNum[ j ] % 3 != 0 )
			result += ( 1 << ( BitNumLength - j - 1 ) );
	return result;
}

void Test( const char * str, int * num, int length, int ans )
{
	cout << str << ": ";
	try
	{
		if( FindNumberAppearOnce2( num, length ) == ans )
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
	int num_1[] = { 2, 4, 6, 2, 3, 4, 4, 2, 6, 6 };
	int ans = 3;
	Test( "test1", num_1, sizeof( num_1 ) / sizeof( int ), ans );
	
	int num_2[] = { -2, 4, 6, 2, 4, 4, 2, 6, 2, 6 };
	ans = -2;
	Test( "test2", num_2, sizeof( num_2 ) / sizeof( int ), ans );
	
	int num_3[] = { 0, 0, 6, -2, 0, -2, 6, -2, 1, 6 };
	ans = 1;
	Test( "test3", num_3, sizeof( num_3 ) / sizeof( int ), ans );
	
	Test( "test4", nullptr, 0, 0 );
	
	return 0;
}
