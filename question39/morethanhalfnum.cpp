#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int RandomInRange( int start, int end )
{
	srand( time( 0 ) );
	return rand() % ( end - start ) + start;
}

void Swap( int * data1, int * data2 )
{
	int temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

int Partition( int * data, int length, int start, int end )
{
	int index = RandomInRange( start, end );
	Swap( &data[ index ], &data[ end ] );
	int small = start - 1;
	for( index = start; index < end; index++ )
	{
		if( data[ index ] < data[ end ] )
		{
			++small;
			Swap( &data[ small ], &data[ index ] );
		}
	}
	++small;
	Swap( &data[ small ], &data[ end ] );
	return small;
}

bool CheckNumMoreThanHalf( int * data, int length, int result )
{
	int count = 0;
	for( int i = 0; i < length; i++ )
		if( data[ i ] == result )
			count++;
	if( count * 2 > length )
		return true;
	else
		return false;
}

int MoreThanHalfNum( int * data, int length )
{
	if( data == nullptr || length <= 0 )
		return 0;
	int start = 0, end = length - 1, middle = length >> 1;
	int index = Partition( data, length, start, end );
	while( index != middle )
	{
		if( index > middle )
			index = Partition( data, length, start, index - 1 );
		else
			index = Partition( data, length, index + 1, end );
	}
	int result = data[ index ];
	if( !CheckNumMoreThanHalf( data, length, result ) )
		result = 0;
	return result;
}

void Test( const char * str, int * data, int length, int ans )
{
	cout << str << ": ";
	if( MoreThanHalfNum( data, length ) == ans )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	int num_1[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	Test( "test1", num_1, sizeof( num_1 ) / sizeof( int ), 2 );
	
	int num_2[] = { 1, 2, 3, 3, 3, 2, 5, 4, 2 };
	Test( "test2", num_2, sizeof( num_2 ) / sizeof( int ), 0 );
	
	Test( "test3", nullptr, 0, 0 );
	
	return 0;
}
