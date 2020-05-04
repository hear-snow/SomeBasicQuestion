#include<iostream>
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

void ReverseSentence( char * str )
{
	if( str == nullptr )
		return;
	char * start = str;
	char * end = str;
	while( *end != '\0' )
		++end;
	--end;
	Reverse( start, end );
	start = end = str;
	while( *start != '\0' )
	{
		if( *start == ' ' )
		{
			++start;
			++end;
		}
		else if( *end == ' ' || *end == '\0' )
		{
			Reverse( start, --end );
			start = ++end;
		}
		else
			++end;
	}
}

void Test( const char * test, char * str )
{
	cout << test << ": ";
	ReverseSentence( str );
	cout << str << endl;
}

int main()
{
	char str[] = "I am a student.";
	Test( "test1", str );
	
	Test( "test2", nullptr );
	
	return 0;
}
