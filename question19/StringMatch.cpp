#include<iostream>
using namespace std;

bool StringMatchProcess( char * str, char * pattern )
{
	if( *str == '\0' && *pattern == '\0' )
		return true;
	if( *str != '\0' && *pattern == '\0' )
		return false;
	
	if( *( pattern + 1 ) == '*' )
		if( *pattern == *str || ( *pattern == '.' && *str != '\0' ) )
			return StringMatchProcess( str + 1, pattern ) || StringMatchProcess( str + 1, pattern + 2 ) || StringMatchProcess( str, pattern + 2 ); 
		else
			return StringMatchProcess( str, pattern + 2 );
		
	if( *pattern == *str || ( *pattern == '.' && *str != '\0' ) )
		return StringMatchProcess( str + 1, pattern + 1 );
	
	return false;
}

bool StringMatch( char * str, char * pattern )
{
	if( str == nullptr || pattern == nullptr )
		return false;
	return StringMatchProcess( str, pattern );
}

void Test1()
{
	cout << "test1: 功能测试" << endl;
	char str[] = "aaa", pattern[] = "ab*a.";
	cout << "正确的输出: 匹配" << endl;
	cout << "实际的输出: ";
	if( StringMatch( str, pattern ) )
		cout << "匹配" << endl;
	else
		cout << "不匹配" << endl;
}

void Test2()
{
	cout << "test2: 负面测试" << endl;
	char * str = nullptr, pattern[] = "ab*a.";
	cout << "正确的输出: 不匹配" << endl;
	cout << "实际的输出: ";
	if( StringMatch( str, pattern ) )
		cout << "匹配" << endl;
	else
		cout << "不匹配" << endl;
}

int main()
{
	Test1();
	Test2(); 
	
	return 0;
}
