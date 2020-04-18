#include<iostream>
#define ROW 4
#define COL 4
using namespace std;

void ClockwisePrintProcess( int** num, int row, int col, int start )
{
	int xAxisNum = col - start - 1;
	int yAxisNum = row - start - 1;
	
	for( int i = start; i <= xAxisNum; i++ )
		cout << num[ start ][ i ] << ' ';
	if( start < yAxisNum )
		for( int i = start + 1; i <= yAxisNum; i++ )
			cout << num[ i ][ xAxisNum ] << ' ';
	if( start < xAxisNum && start < yAxisNum )
		for( int i = xAxisNum - 1; i >= start; i-- )
			cout << num[ yAxisNum ][ i ] << ' ';
	if( start < yAxisNum - 1 && start < xAxisNum )
		for( int i = yAxisNum - 1; i >= start + 1; i-- )
			cout << num[ i ][ start ] << ' ';
}

void ClockwisePrintMatrix( int** num, int row, int col )
{
	if( num == nullptr || row <= 0 || col <= 0 )
		return;
	int start = 0;
	while( row > start * 2 && col > start * 2 )
	{
		ClockwisePrintProcess( num, row, col, start );
		start++;
	}
	cout << endl;
}

void Test1()
{
	cout << "test1: 功能测试" << endl;
	cout << "正确的输出: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10" << endl;
	int** num = new int*[ ROW ];
	for( int i = 0; i < 4; i++ )
	{
		num[ i ] = new int[ COL ];
		for( int j = 0; j < 4; j++ )
			num[ i ][ j ] = COL * i + j + 1;
	}
	cout << "实际的输出: ";
	ClockwisePrintMatrix( num, ROW, COL );
}

void Test2()
{
	cout << "test2: 负面测试" << endl;
	cout << "正确的输出: " << endl;
	int** num = nullptr;
	cout << "实际的输出: ";
	ClockwisePrintMatrix( num, ROW, COL );
}

int main()
{
	Test1();
	Test2();
	
	return 0;
}
