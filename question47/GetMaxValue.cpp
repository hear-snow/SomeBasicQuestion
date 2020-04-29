#include<iostream>
using namespace std;

int Max( int num1, int num2 )
{
	return num1 > num2 ? num1 : num2;
}

int GetMaxValue( int * num, int rows, int cols )
{
	if( num == nullptr || rows <= 0 || cols <= 0 )
		return 0;
	int * tmp_data = new int[ cols ];
	for( int i = 0; i < rows; i++ )
		for( int j = 0; j < cols; j++ )
		{
			int left = 0;
			int up = 0;
			if( i > 0 )
				up = tmp_data[ j ];
			if( j > 0 )
				left = tmp_data[ j - 1 ];
			tmp_data[ j ] = Max( up, left ) + num[ i * cols + j ];
		}
	int maxValue = tmp_data[ cols - 1 ];
	delete [] tmp_data;
	return maxValue;
}

void Test( const char * str, int * num, int rows, int cols, int ans )
{
	cout << str << ": ";
	if( GetMaxValue( num, rows, cols ) == ans )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl; 
}

int main()
{
	int num_1[] = { 1, 10, 3, 8, 12, 2, 9, 6, 5, 7, 4, 11, 3, 7, 16, 5 };
	int rows = 4, cols = 4, ans = 53;
	Test( "test1", num_1, rows, cols, ans );
	
	int num_2[] = { 1, 8, 9, 0 };
	rows = 2;
	cols = 2;
	ans = 10;
	Test( "test2", num_2, rows, cols, ans );
	
	Test( "test3", nullptr, 0, 0, 0 );
	
	return 0;
}
