#include<iostream>
using namespace std;

int Add( int num1, int num2 )
{
	int sum, carry;
	do
	{
		sum = num1 ^ num2;
		carry = ( num1 & num2 ) << 1;
		num1 = sum;
		num2 = carry;
	}
	while( num2 != 0 );
	return sum;
}

void Test( const char * str, int num1, int num2, int ans )
{
	cout << str << ": ";
	if( Add( num1, num2 ) == ans )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	int num1 = 2;
	int num2 = 3;
	int ans = 5;
	Test( "test1", num1, num2, ans );
	
	num1 = -2;
	num2 = -3;
	ans = -5;
	Test( "test2", num1, num2, ans );
	
	num1 = -2;
	num2 = 2;
	ans = 0;
	Test( "test3", num1, num2, ans );
	
	return 0;
} 
