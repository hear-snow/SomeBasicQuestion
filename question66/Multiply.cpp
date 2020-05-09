#include<iostream>
#include<vector>
using namespace std;

void Multiply( const vector< int > & A, vector< int > & B )
{
	int length1 = A.size();
	int length2 = B.size(); 
	if( length1 == length2 && length1 > 0 )
	{
		B[ 0 ] = 1;
		for( int i = 1; i < length2; ++i )
			B[ i ] = B[ i - 1 ] * A[ i - 1 ];
		int tmp = 1;
		for( int i = length2 - 2; i >= 0; --i )
		{
			tmp *= A[ i + 1 ];
			B[ i ] *= tmp;
		}
	}
}

void Test( const char * str, const vector< int > & A, const vector< int > & ans )
{
	cout << str << ": ";
	int length = A.size();
	vector< int > B;
	for( int i = 0; i < length; ++i )
		B.push_back( 0 );
	Multiply( A, B );
	bool flag = true;
	for( int i = 0; i < length; ++i )
		if( B[ i ] != ans[ i ] )
			flag = false;
	if( flag )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	vector< int > A1 = { 1, 2, 3, 4 };
	vector< int > ans1 = { 24, 12, 8, 6 };
	Test( "test1", A1, ans1 );
	
	vector< int > A2 = { 0, 1, 2, 3 };
	vector< int > ans2 = { 6, 0, 0, 0 };
	Test( "test2", A2, ans2 );
	
	return 0;
} 
