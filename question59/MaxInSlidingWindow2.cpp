#include"queuewithmax.h"
#include<iostream>
using namespace std;

void MaxInSlidingWindow( int * num, int length, int windowLength )
{
	if( num == nullptr || length <= 0 || windowLength > length )
		return;
	QueueWithMax< int > numQueue;
	for( int i = 0; i < length; i++ )
	{
		if( i < windowLength )
			numQueue.push_back( num[ i ] );
		else
		{
			cout << numQueue.max() << ' ';
			numQueue.pop_front();
			numQueue.push_back( num[ i ] );
		}
	}
	cout << numQueue.max() << endl;
}

void Test( const char * str, int * num, int length, int windowLength )
{
	cout << str << ": ";
	MaxInSlidingWindow( num, length, windowLength );
}

int main()
{
	int num_1[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
	int windowLength = 3;
	Test( "test1", num_1, sizeof( num_1 ) / sizeof( int ), windowLength );
	
	return 0;
}
