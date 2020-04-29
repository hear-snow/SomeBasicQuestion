#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool compare( const string s1, const string s2 )
{
	string tmp1 = s1 + s2;
	string tmp2 = s2 + s1;
	return tmp1 < tmp2;
}

string ConnectMinNum( int * num, int length )
{
	if( num == nullptr || length <= 0 )
		throw exception();
	string * data_str = new string[ length ];
	for( int i = 0; i < length; i++ )
		data_str[ i ] = to_string( num[ i ] );
	sort( data_str, data_str + length, compare );
	string ans;
	for( int i = 0; i < length; i++ )
		ans += data_str[ i ];
	return ans;
}

void Test( const char * str, int * num, int length, int ans )
{
	cout << str << ": ";
	try
	{
		string minNum = ConnectMinNum( num, length );
		if( minNum.compare( to_string( ans ) ) == 0 )
			cout << "Passed!" << endl;
		else
			cout << "Failed!" << endl;
	}
	catch( const exception & )
	{
		cout << "Bad Input!" << endl;
	}
}

int main()
{
	int num_1[] = { 3, 32, 321 };
	int ans = 321323;
	Test( "test1", num_1, sizeof( num_1 ) / sizeof( int ), ans );
	
	int num_2[] = { 1, 4, 3, 2 };
	ans = 1234;
	Test( "test2", num_2, sizeof( num_2 ) / sizeof( int ), ans );
	
	int num_3[] = { 43, 23, 37 };
	ans = 233743;
	Test( "test3", num_3, sizeof( num_3 ) / sizeof( int ), ans );
	
	Test( "test4", nullptr, 0, 0 );
	
	return 0;
} 
