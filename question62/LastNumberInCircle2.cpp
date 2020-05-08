#include<iostream>
#include<list>
using namespace std;

int LastNumberInCircle( int n, int m )
{
	if( n < 1 || m < 1 )
		return -1;
	int ans = 0;
	for( int i = 2; i <= n; i++ )
		ans = ( ans + m ) % i;
	return ans;
}

void Test( const char * str, int n, int m, int ans )
{
	cout << str << ": ";
	int num = LastNumberInCircle( n, m );
	if( num == ans )
		cout << "Passed!" << endl;
	else if( num == -1 )
		cout << "Bad Input!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	int n = 5;
	int m = 3;
	int ans = 3;
	Test( "test1", n, m, ans );
	
	n = 1;
	m = 1;
	ans = 0;
	Test( "test2", n, m, ans );
	
	n = 5;
	m = 0;
	ans = 0;
	Test( "test3", n, m, ans );
	
	return 0;
}
