#include<iostream>
using namespace std;

void PrintContinuousSequence( int start, int end )
{
	for( int i = start; i <= end; i++ )
		cout << i << ' ';
	cout << "  ";
}

void FindContinuousSequence( int target )
{
	if( target < 3 )
		return;
	int start = 1;
	int end = 2;
	int limit = ( target + 1 ) / 2;
	int sum = start + end;
	while( start < limit )
	{
		if( sum == target )
			PrintContinuousSequence( start, end );
		if( sum < target )
		{
			end++;
			sum += end;
		}
		else
		{
			sum -= start;
			start++;
		}
	}
}

void Test( const char * str, int target )
{
	cout << str << ": ";
	FindContinuousSequence( target );
	cout << endl;
}

int main()
{
	int target = 15;
	Test( "test1", target );
	
	target = 9;
	Test( "test2", target );
	
	target = 1;
	Test( "test3", target );
	
	return 0;
}
