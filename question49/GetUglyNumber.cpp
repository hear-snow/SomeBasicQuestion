#include<iostream>
using namespace std;

int Min( int num1, int num2, int num3 )
{
	int min = num1 < num2 ? num1 : num2;
	return min < num3 ? min : num3;
}

int GetUglyNumber( int number )
{
	if( number <= 0 )
		return 0;
	int location_2 = 0;
	int location_3 = 0;
	int location_5 = 0;
	int * uglyNumberData = new int[ number ];
	uglyNumberData[ 0 ] = 1;
	for( int i = 1; i < number; i++ )
	{
		while( uglyNumberData[ location_2 ] * 2 <= uglyNumberData[ i - 1 ] )
			location_2++;
		while( uglyNumberData[ location_3 ] * 3 <= uglyNumberData[ i - 1 ] )
			location_3++;
		while( uglyNumberData[ location_5 ] * 5 <= uglyNumberData[ i - 1 ] )
			location_5++;
		uglyNumberData[ i ] = Min( uglyNumberData[ location_2 ] * 2, uglyNumberData[ location_3 ] * 3, uglyNumberData[ location_5 ] * 5 );
	}
	int ans = uglyNumberData[ number - 1 ];
	delete [] uglyNumberData;
	return ans;
}

void Test( const char * str, int number, int ans )
{
	cout << str << ": ";
	if( GetUglyNumber( number ) == ans )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	Test( "test1", 1, 1 );
	
	Test( "test2", 9, 10 );
	
	Test( "test3", 1500, 859963392 );
	
	Test( "test4", 0, 0 );
	
	return 0;
}
