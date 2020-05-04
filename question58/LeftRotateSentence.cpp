#include<iostream>
#include<cstring>
using namespace std;

void Reverse( char * start, char * end )
{
	while( start < end )
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		++start;
		--end;
	}
}

void LeftRotateSentence( char * str, int n )
{
	if( str == nullptr )
		return;
	int length = strlen( str );
	if( n > length || n <= 0 )
		return;
	Reverse( str, str + length - 1 );
	Reverse( str, str + length - n - 1 );
	Reverse( str + length - n, str + length - 1 );
}

void Test( const char * test, char * str, int n )
{
	cout << test << ": ";
	LeftRotateSentence( str, n );
	cout << str << endl;
}

int main()
{
	char str_1[] = "abcdefg";
	int n = 2;
	Test( "test1", str_1, n );
	
	char str_2[] = "abcdefg";
	n = 7;
	Test( "test2", str_2, n );
	
	Test( "test3", nullptr, 0 );
	
	return 0;
}
