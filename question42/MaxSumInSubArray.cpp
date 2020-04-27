#include<iostream>
#include<climits>
using namespace std;

bool BadInput = false; 

int MaxSumInSubArray( int * num, int length )
{
	if( num == nullptr || length < 1 )
	{
		BadInput = true;
		return 0;
	}
	BadInput = false;
	int maxSum = INT_MIN, currentSum = 0;
	for( int i = 0; i < length; i++ )
	{
		if( currentSum <= 0 )
			currentSum = num[ i ];
		else
			currentSum += num[ i ];
		if( currentSum > maxSum )
			maxSum = currentSum;
	}
	return maxSum;
}

void Test( const char * str, int * num, int length, int ans )
{
	cout << str << ": ";
	if( MaxSumInSubArray( num, length ) == ans )
	{
		if( !BadInput )
			cout << "Passed!" << endl;
		else if( num == nullptr || length < 1 )
			cout << "Passed!" << endl;
		else
			cout << "Failed!" << endl;
	}
	else
		cout << "Failed!" << endl;
}

int main()
{
	int num_1[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	Test( "test1", num_1, sizeof( num_1 ) / sizeof( int ), 18 );
	
	Test( "test2", nullptr, 0, 0 );
	
	return 0;
} 
