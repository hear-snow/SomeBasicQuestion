#include<iostream>
using namespace std;

int GetMissingNumber( int * num, int length, int start, int end )
{
	if( num == nullptr || length <= 0 )
		return -1;
	while( start <= end )
	{
		int middle = ( start + end ) / 2;
		if( num[ middle ] == middle )
		{
			if( ( middle < length - 1 && num[ middle + 1 ] != middle + 1 ) || middle == length - 1 )
				return middle + 1;
			else
				start = middle + 1;
		}
		else
			end = middle - 1;
	}
	if( end == -1 )		//如果第1个数字缺失，此时end == -1、start == 0，应返回0
		return 0;
	return -1;
}

void Test( const char * str, int * num, int length, int ans )
{
	cout << str << ": ";
	if( GetMissingNumber( num, length, 0, length - 1 ) == ans )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl; 
}

int main()
{
	int num_1[] = { 0, 1, 2, 3, 5, 6 };
	int ans = 4;
	Test( "test1", num_1, sizeof( num_1 ) / sizeof( int ), ans );
	
	int num_2[] = { 0, 1, 2, 3, 4, 5 };
	ans = 6;
	Test( "test2", num_2, sizeof( num_2 ) / sizeof( int ), ans );
	
	int num_3[] = { 1, 2, 3, 4, 5, 6 };
	ans = 0;
	Test( "test3", num_3, sizeof( num_3 ) / sizeof( int ), ans );
	
	Test( "test4", nullptr, 0, -1 );
	
	return 0;
}
