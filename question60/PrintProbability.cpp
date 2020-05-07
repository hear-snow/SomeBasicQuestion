#include<iostream>
#include<cmath>
using namespace std;

void CountProbability( int number, int current, int currentSum, int * pSumNumber )
{
	if( current == 0 )
	{
		pSumNumber[ currentSum - number ]++;
		return;
	}
	for( int i = 1; i <= 6; i++ )
		CountProbability( number, current - 1, currentSum + i, pSumNumber );
}

void PrintProbability( int number )
{
	if( number <= 0 )
		return;
	int length = number * 6 - number + 1;
	int * pSumNumber = new int[ length ];
	for( int i = 0; i < length; i++ )
		pSumNumber[ i ] = 0;
	int currentSum = 0;
	for( int i = 1; i <= 6; i++ )
		CountProbability( number, number - 1, currentSum + i, pSumNumber );
	int total = pow( 6.0, number );
	for( int i = 0; i < length; i++ )
	{
		double ratio = ( double )pSumNumber[ i ] / total;
		cout << i + number << '\t' << ratio << endl;
	}
	delete [] pSumNumber;
}

void Test( const char * str, int n )
{
	cout << str << ": " << endl;
	PrintProbability( n );
}

int main()
{
	int n = 6;
	Test( "test1", n );
	
	return 0;
}
