#include<iostream>
using namespace std;

int GetNumberSameAsIndex( int * num, int length )
{
	if( num == nullptr || length <= 0 )
		return -1;
	int start = 0;
	int end = length - 1;
	while( start <= end )
	{
		int middle = ( start + end ) / 2;
		if( num[ middle ] == middle )
			return middle;
		else if( num[ middle < middle ] )
			start = middle + 1;
		else
			end = middle - 1;
	}
	return -1;
}

void Test( const char * str, int * num, int length, int ans )
{
	cout << str << ": ";
	if( GetNumberSameAsIndex( num, length ) == ans )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	int num_1[] = { -6, -4, -1, 0, 2, 5, 8 };
	int ans = 5;
	Test( "test1", num_1, sizeof( num_1 ) / sizeof( int ), ans );
	
	int num_2[] = { 0, 2, 3, 5, 8 };
	ans = 0;
	Test( "test2", num_2, sizeof( num_2 ) / sizeof( int ), ans );
	
	int num_3[] = { -6, -4, -3, -1, 3, 4, 6 };
	ans = 6;
	Test( "test3", num_3, sizeof( num_3 ) / sizeof( int ), ans );
	
	int num_4[] = { -6, -4, -1, 0, 2, 6, 8 };
	ans = -1;
	Test( "test4", num_4, sizeof( num_4 ) / sizeof( int ), ans );
	
	ans = -1;
	Test( "test5", nullptr, 0, ans );
	
	return 0;
}
