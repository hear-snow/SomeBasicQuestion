#include<iostream>
#include<string>
using namespace std;

void CountNumberAfterTranslation( string & num_str, int length, int & count )
{
	if( length == 1 || length == 0 )
	{
		++count;
		return;
	}
	int digit1 = num_str[ length - 1 ] - '0';
	int digit2 = num_str[ length - 2 ] - '0';
	int num_tmp = digit2 * 10 + digit1;
	if( num_tmp >= 10 && num_tmp <= 25 && length >= 2 )
		CountNumberAfterTranslation( num_str, length - 2, count );
	CountNumberAfterTranslation( num_str, length - 1, count );
}

int TranslationNumberToString( int num )
{
	if( num < 0 )
		return 0;
	string num_str = to_string( num );
	int length = num_str.length();
	int count = 0;
	CountNumberAfterTranslation( num_str, length, count );
	return count;
}

void Test( const char * str, int num, int ans )
{
	cout << str << ": ";
	int numbers = TranslationNumberToString( num );
	if( numbers == ans )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	Test( "test1", 12258, 5 );
	
	Test( "test2", 16212, 6 );
	
	Test( "test3", 252625, 4 );
	
	Test( "test4", 252525, 8 );
	
	Test( "test5", 0, 1 );
	
	Test( "test6", -1, 0 );
	
	return 0;
}
