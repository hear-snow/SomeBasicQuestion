#include<iostream>
#include<deque>
using namespace std;

void MaxInWindows( int * num, int length, int windowLength )
{
	if( num == nullptr || length <= 0 || windowLength > length || windowLength <= 0 )
	{
		cout << endl;
		return;
	}
	deque< int > index;
	for( int i = 0; i < length; i++ )
	{
		if( i < windowLength )
		{
			while( !index.empty() && num[ i ] > num[ index.back() ] )
				index.pop_back();
			index.push_back( i );
		}
		else
		{
			cout << num[ index.front() ] << ' ';
			while( !index.empty() && num[ i ] > num[ index.back() ] )
				index.pop_back();
			if( !index.empty() && i - index.front() >= windowLength )
				index.pop_front();
			index.push_back( i );
		}
	}
	cout << num[ index.front() ] << endl;
}

void Test( const char * str, int * num, int length, int windowLength )
{
	cout << str << ": ";
	MaxInWindows( num, length, windowLength );
}

int main()
{
	int num_1[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
	int windowLength = 3;
	Test( "test1", num_1, sizeof( num_1 ) / sizeof( int ), windowLength );
	
	windowLength = 10;
	Test( "test2", num_1, sizeof( num_1 ) / sizeof( int ), windowLength );
	
	Test( "test3", nullptr, 0, 0 );
	
	return 0;
} 
