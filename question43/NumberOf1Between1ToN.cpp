#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int PowerBase10( unsigned int x )
{
	if( x == 0 )
		return 1;
	if( x == 1 )
		return 10;
	if( x & 1 )
		return PowerBase10( x >> 1 ) * PowerBase10( x >> 1 ) * PowerBase10( 1 );
	else
		return PowerBase10( x >> 1 ) * PowerBase10( x >> 1 );
}

int NumberOf1( const char * str )
{
	if( str == nullptr || *str > '9' || *str < '0' || *str == '\0' )
		return 0;
	int firstPlace = *str - '0';
	int length = strlen( str );
	if( length == 1 && firstPlace == 0 )
		return 0;
	if( length == 1 && firstPlace > 0 )
		return 1;
	
	int numOfFirstDigit = 0;
	if( firstPlace > 1 )
		numOfFirstDigit = PowerBase10( length - 1 );
	else
		numOfFirstDigit = atoi( str + 1 ) + 1;
	int numOfOtherDigit = firstPlace * ( length - 1 ) * PowerBase10( length - 2 );
	int numOfRecursive = NumberOf1( str + 1 );
	return numOfFirstDigit + numOfOtherDigit + numOfRecursive;
}

int NumberOf1Between1ToN( int num )
{
	if( num <= 0 )
		return 0;
	char str[ 20 ];
	sprintf( str, "%d", num );
	return NumberOf1( str );
}

void Test( const char * str, int num, int ans )
{
	cout << str << ": ";
	if( NumberOf1Between1ToN( num ) == ans )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	Test( "test1", 5, 1 );
	
	Test( "test2", 10, 2 );
	
	Test( "test3", 55, 16 );
	
	Test( "test4", 21345, 18821 );
	
	return 0;
}
