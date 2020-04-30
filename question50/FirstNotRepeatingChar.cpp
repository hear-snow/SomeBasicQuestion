#include<iostream>
using namespace std;

char FirstNotRepeatingChar( const char * str )
{
	if( str == nullptr )
		return '\0';
	unsigned int * charCountNumber = new unsigned int[ 256 ];
	for( int i = 0; i < 256; i++ )
		charCountNumber[ i ] = 0;
	for( const char * tmp = str; *tmp != '\0'; tmp++ )
		charCountNumber[ *tmp ]++;
	for( const char * tmp = str; *tmp != '\0'; tmp++ )
		if( charCountNumber[ *tmp ] == 1 )
			return *tmp;
	delete [] charCountNumber;
	return '\0';
}

void Test( const char * test, const char * str, char ans )
{
	cout << test << ": ";
	if( FirstNotRepeatingChar( str ) == ans )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl; 
}

int main()
{
	Test( "test1", "abaccdeff", 'b' );
	
	Test( "test2", "$%^&*(@$%@", '^' );
	
	Test( "test3", nullptr, '\0' );
	
	return 0;
} 
