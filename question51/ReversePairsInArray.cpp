#include<iostream>
using namespace std;

int ReversePairsInArrayProcess( int * num, int * copy, int start, int end )
{
	if( start == end )
	{
		copy[ start ] = num[ start ];
		return 0; 
	}
	int middle = ( start + end ) / 2;
	int left = ReversePairsInArrayProcess( copy, num, start, middle );
	int right = ReversePairsInArrayProcess( copy, num, middle + 1, end );
	
	int count = left + right;
	int location1 = middle;
	int location2 = end;
	int currentInCopy = end;
	while( location1 >= start && location2 >= middle + 1 )
	{
		if( num[ location1 ] > num[ location2 ] )
		{
			count += location2 - middle;
			copy[ currentInCopy-- ] = num[ location1-- ];
		}
		else
			copy[ currentInCopy-- ] = num[ location2-- ];
	}
	while( location1 >= start )
		copy[ currentInCopy-- ] = num[ location1-- ];
	while( location2 >= middle + 1 )
		copy[ currentInCopy-- ] = num[ location2-- ];
	return count;
}

int ReversePairsInArray( int * num, int length )
{
	if( num == nullptr || length <= 0 )
		return 0;
	int * copy = new int[ length ];
	for( int i = 0; i < length; i++ )
		copy[ i ] = num[ i ];
	int count = ReversePairsInArrayProcess( num, copy, 0, length - 1 );
	delete [] copy;
	return count;
}

void Test( const char * str, int * num, int length, int ans )
{
	cout << str << ": ";
	if( ReversePairsInArray( num, length ) == ans )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	int num_1[] = { 7, 5, 6, 4 };
	Test( "test1", num_1, sizeof( num_1 ) / sizeof( int ), 5 );
	
	int num_2[] = { 5, 2, 2, 4 };
	Test( "test2", num_2, sizeof( num_2 ) / sizeof( int ), 3 );
	
	int num_3[] = { 1 };
	Test( "test3", num_3, sizeof( num_3 ) / sizeof( int ), 0 );
	
	Test( "test4", nullptr, 0, 0 );
	
	return 0;
}
