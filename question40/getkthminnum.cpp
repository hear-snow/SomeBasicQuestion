#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void Swap( int * data_1, int * data_2 )
{
	int tmp = *data_1;
	*data_1 = *data_2;
	*data_2 = tmp;
}

int RandomNumber( int start, int end )
{
	srand( time( 0 ) );
	return rand() % ( end - start ) + start;
}

int Partition( int * num, int length, int start, int end )
{
	int index = RandomNumber( start, end );
	Swap( &num[ index ], &num[ end ] );
	int small = start - 1;
	for( index = start; index < end; index++ )
	{
		if( num[ index ] < num[ end ] )
		{
			++small;
			if( small != index )
				Swap( &num[ small ], &num[ index ] );
		}
	}
	++small;
	Swap( &num[ small ], &num[ end ] );
	return small;
}

void GetkthMinNum( int * num, int * kthMinNum, int length, int k )
{
	if( num == nullptr || kthMinNum == nullptr || length <= 0 || k <= 0 )
		return;
	int start = 0, end = length - 1;
	int index = Partition( num, length, start, end );
	while( index != k - 1 )
	{
		if( index > k - 1 )
			index = Partition( num, length, start, index - 1 );
		else
			index = Partition( num, length, index + 1, end );
	}
	for( int i = 0; i < k; i++ )
		kthMinNum[ i ] = num[ i ];
}

bool CheckAnswer( int * ans, int * kthMinNum, int k )
{
	bool kthMinNumIsRight = true;
	for( int i = 0; i < k; i++ )
	{
		int j = 0;
		for( ; j < k; j++ )
			if( kthMinNum[ i ] == ans[ j ] )
				break;
		if( j == k )
			kthMinNumIsRight = false;
	}
	return kthMinNumIsRight;
}

void Test( const char * str, int * num, int * ans, int length, int k )
{
	cout << str << ": ";
	int * kthMinNum = new int[ k ];
	GetkthMinNum( num, kthMinNum, length, k );
	if( CheckAnswer( ans, kthMinNum, k ) )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	int num_1[] = { 4, 5, 1, 6, 2, 7, 3, 8 }, ans_1[] = { 1, 2, 3, 4 };
	Test( "test1", num_1, ans_1, sizeof( num_1 ) / sizeof( int ), sizeof( ans_1 ) / sizeof( int ) );
	
	Test( "test2", nullptr, nullptr, 0, 0 );
	
	return 0;
}
