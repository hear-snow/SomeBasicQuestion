#include<iostream>
using namespace std;
enum State { kVaild, kInvaild };
int g_nState = kVaild;

int StrToIntProcess( const char * str, bool minus )
{
	long long num = 0;
	while( *str != '\0' )
	{
		if( *str < '0' || *str > '9' )
		{
			g_nState = kInvaild;
			return 0;
		}
		else
		{
			num = num * 10 + *str - '0';
			if( num > 0x7FFFFFFF )
			{
				g_nState = kInvaild;
				return 0;
			}
			str++;
		}
	}
	if( minus )
		num *= -1;
	return ( int )num;
}

int StrToInt( const char * str )
{
	g_nState = kVaild;
	if( str == nullptr || *str == '\0' )
	{
		g_nState = kInvaild;
		return 0;
	}
	bool minus = false;
	if( *str == '+' )
		str++;
	else if( *str == '-' )
	{
		minus = true;
		str++;
	}
	if( *str == '\0' )
	{
		g_nState = kInvaild;
		return 0;
	}
	else
		return StrToIntProcess( str, minus );
}

void Test( const char * test, const char * str, int ans )
{
	cout << test << ": ";
	if( StrToInt( str ) == ans && g_nState == kVaild )
		cout << "Passed!" << endl;
	else if( g_nState == kInvaild )
		cout << "Bad Input!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	char str_1[] = "123";
	int ans = 123;
	Test( "test1", str_1, ans );
	
	char str_2[] = "-123";
	ans = -123;
	Test( "test2", str_2, ans );
	
	char str_3[] = "+123";
	ans = 123;
	Test( "test3", str_3, ans );
	
	char str_4[] = "0";
	ans = 0;
	Test( "test4", str_4, ans );
	
	char str_5[] = "+";
	ans = 0;
	Test( "test5", str_5, ans );
	
	char str_6[] = "-";
	ans = 0;
	Test( "test6", str_6, ans );
	
	char str_7[] = "1976169841436117821";
	ans = 0;
	Test( "test7", str_7, ans );
	
	char str_8[] = "";
	ans = 0;
	Test( "test8", str_8, ans );
	
	char str_9[] = "75%1#*64";
	ans = 0;
	Test( "test9", str_9, ans );
	
	return 0;
}
