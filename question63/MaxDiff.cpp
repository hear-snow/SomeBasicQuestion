#include<iostream>
using namespace std;

int MaxDiff( int * num, int length )
{
	if( num == nullptr || length < 2 )
		return -1;
	int min = num[ 0 ];
	int maxDiff = num[ 1 ] - min;
	for( int i = 2; i < length; i++ )
	{
		if( num[ i - 1 ] < min )
			min = num[ i - 1 ];
		int currentDiff = num[ i ] - min;
		if( currentDiff > maxDiff )
			maxDiff = currentDiff;
	}
	return maxDiff;
}

void Test( const char * str, int * num, int length, int ans )
{
	cout << str << ": ";
	int maxDiff = MaxDiff( num, length );
	if( maxDiff == ans )
		cout << "Passed!" << endl;
	else if( maxDiff == -1 )
		cout << "Bad Input!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	int num_1[] = { 9, 11, 8, 5, 7, 12, 16, 14 };
	int ans = 11;
	Test( "test1", num_1, sizeof( num_1 ) / sizeof( int ), ans );
	
	int num_2[] = { 9, 9, 9, 9, 9 };
	ans = 0;
	Test( "test2", num_2, sizeof( num_2 ) / sizeof( int ), ans );
	
	int num_3[] = { 2, 14 };
	ans = 12;
	Test( "test3", num_3, sizeof( num_3 ) / sizeof( int ), ans );
	
	Test( "test4", nullptr, 0, ans );
	
	return 0;
}
