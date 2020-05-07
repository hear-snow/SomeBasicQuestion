#include<iostream>
#include<algorithm>
using namespace std;

int compare( const void * arg1, const void * arg2 )
{
	return *( ( int * )arg1 ) - *( ( int * )arg2 );
}

bool IsContinuous( int * num, int length )
{
	if( num == nullptr || length < 5 )
		return false;
	qsort( num, length, sizeof( int ), compare );
	int numberOfZero = 0;
	int numberOfGap = 0;
	for( int i = 0; num[ i ] == 0 && i < length; ++i )
		++numberOfZero;
	int small = numberOfZero;
	int big = small + 1;
	while( big < length )
	{
		if( num[ big ] == num[ small ] )
			return false;
		numberOfGap += num[ big ] - num[ small ] - 1;
		small = big;
		++big;
	}
	return numberOfZero >= numberOfGap ? true : false;
}

void Test( const char * str, int * num, int length, bool ans )
{
	cout << str << ": ";
	if( IsContinuous( num, length ) == ans )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	int num_1[] = { 2, 3, 5, 6, 0 };
	bool ans = true;
	Test( "test1", num_1, sizeof( num_1 ) / sizeof( int ), ans );
	
	int num_2[] = { 0, 3, 5, 6, 0 };
	ans = true;
	Test( "test2", num_2, sizeof( num_2 ) / sizeof( int ), ans );
	
	int num_3[] = { 7, 3, 5, 6, 1 };
	ans = false;
	Test( "test3", num_3, sizeof( num_3 ) / sizeof( int ), ans );
	
	int num_4[] = { 1, 0, 5, 0, 0 };
	ans = true;
	Test( "test4", num_4, sizeof( num_4 ) / sizeof( int ), ans );
	
	int num_5[] = { 2, 11, 5, 4, 0 };
	ans = false;
	Test( "test5", num_5, sizeof( num_5 ) / sizeof( int ), ans );
	
	return 0;
}
