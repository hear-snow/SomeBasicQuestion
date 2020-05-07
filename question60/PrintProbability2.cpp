#include<iostream>
#include<cmath>
using namespace std;

void PrintProbability( int number )
{
	if( number <= 0 )
		return;
	int length = number * 6 - number + 1;
	int * pSumNumber[ 2 ];
	pSumNumber[ 0 ] = new int[ length ];
	pSumNumber[ 1 ] = new int[ length ];
	for( int i = 0; i < length; i++ )
	{
		pSumNumber[ 0 ][ i ] = 0;
		pSumNumber[ 1 ][ i ] = 0;
	}
	int flag = 0;
	for( int i = 0; i < 6; i++ )
	{
		pSumNumber[ flag ][ i ] = 1;
	}
	for( int i = 2; i <= number; i++ )
	{
		for( int j = 0; j < i * 6 - i + 1; j++ )
		{
			pSumNumber[ 1 - flag ][ j ] = 0;
			for( int k = j ; k > 0 && k >= j - 5; k-- )
				pSumNumber[ 1 - flag ][ j ] += pSumNumber[ flag ][ k ];
		}
		flag = 1 - flag;
	}
	int total = pow( 6.0, number );
	for( int i = 0; i < length; i++ )
	{
		double ratio = ( double )pSumNumber[ flag ][ i ] / total;
		cout << i + number << '\t' << ratio << endl;
	}
	delete [] pSumNumber[ 1 ];
	delete [] pSumNumber[ 0 ];
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
