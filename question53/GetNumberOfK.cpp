#include<iostream>
using namespace std;

int GetFirstK( int * num, int length, int start, int end, int k )
{
	if( start > end )
		return -1;
	int middle = ( start + end ) / 2;
	if( num[ middle ] == k )
	{
		if( ( middle > 0 && num[ middle - 1 ] != k ) || middle == 0 )
			return middle;
		else
			end = middle - 1;
	}
	else if( num[ middle ] > k )
		end = middle - 1;
	else
		start = middle + 1;
	return GetFirstK( num, length, start, end, k );
}

int GetLastK( int * num, int length, int start, int end, int k )
{
	if( start > end )
		return -1;
	int middle = ( start + end ) / 2;
	if( num[ middle ] == k )
	{
		if( ( middle < length - 1 && num[ middle + 1 ] != k ) || middle == length - 1 )
			return middle;
		else
			start = middle + 1;
	}
	else if( num[ middle ] > k )
		end = middle - 1;
	else
		start = middle + 1;
	return GetLastK( num, length, start, end, k );
}

int GetNumberOfK( int * num, int length, int k )
{
	if( num == nullptr || length <= 0 )
		return 0;
	int first = GetFirstK( num, length, 0, length - 1, k );
	int last = GetLastK( num, length, 0, length - 1, k );
	if( first > -1 && last > -1 )
		return last - first + 1;
	return 0;
}

void Test( const char * str, int * num, int length, int k, int ans )
{
	cout << str << ": ";
	if( GetNumberOfK( num, length, k ) == ans )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	int num_1[] = { 1, 2, 3, 3, 3, 4, 5 };
	int k = 3;
	int ans = 3;
	Test( "test1", num_1, sizeof( num_1 ) / sizeof( int ), k, ans );
	
	int num_2[] = { 1, 2, 3, 4, 4, 5, 5 };
	k = 5;
	ans = 2;
	Test( "test2", num_2, sizeof( num_2 ) / sizeof( int ), k, ans );
	
	int num_3[] = { 1, 2, 3, 4, 5, 6, 7 };
	k = 8;
	ans = 0;
	Test( "test3", num_3, sizeof( num_3 ) / sizeof( int ), k, ans );
	
	int num_4[] = { 1, 2, 3, 4, 5 };
	k = 1;
	ans = 1;
	Test( "test4", num_4, sizeof( num_4 ) / sizeof( int ), k, ans );
	
	Test( "test5", nullptr, 0, 5, 0 );
	
	return 0;
}
