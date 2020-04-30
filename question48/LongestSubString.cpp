#include<iostream>
#include<string>
using namespace std;

int LongestSubString( const string str )
{
	if( str.size() == 0 )
		return 0;
	int currentLength = 0, maxLength = 0;
	int * charLocation = new int[ 26 ];
	for( int i = 0; i < 26; ++i )
		charLocation[ i ] = -1;
	for( int i = 0; i < str.length(); ++i )
	{
		int currentChar = str[ i ] - 'a';
		if( charLocation[ currentChar ] < 0 || i - charLocation[ currentChar ] > currentLength )
			++currentLength;
		else
			currentLength = i - charLocation[ currentChar ];
		charLocation[ currentChar ] = i;
		if( currentLength > maxLength )
			maxLength = currentLength;
	}
	delete [] charLocation;
	return maxLength;
}

void Test( const char * test, const string & str, int ans )
{
	cout << test << ": ";
	if( LongestSubString( str ) == ans )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	string str_1( "arabcacfr" );
	Test( "test1", str_1, 4 );
	
	string str_2( "adkzbdksacacfr" );
	Test( "test2", str_2, 7 );
	
	string str_3( "aabbaaccaa" );
	Test( "test3", str_3, 2 );
	
	string str_4( "" );
	Test( "test4", str_4, 0 );
	
	return 0;
}
