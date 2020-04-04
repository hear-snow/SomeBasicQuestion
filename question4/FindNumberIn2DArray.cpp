#include<iostream>
#define ROW 4
#define COL 4
using namespace std;

bool Find( int ( *num )[ 4 ], int rows, int columns, int target )
{
	if( num != nullptr && rows > 0 && columns > 0 )
	{
		int row = 0, column = columns - 1;
		while( row < rows && column > 0 )
		{
			if( num[ row ][ column ] == target )
				return true;
			else if( num[ row ][ column ] > target )
				column--;
			else
				row++;
		}
	}
	return false;
}

void Test1()
{
	int num[ ROW ][ COL ] = { { 1, 2, 8, 9}, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	int target = 7;
	cout << "test1: 二维数组中包含要查找的数字" << endl; 
	cout << "正确的结果: 包含" << endl;
	cout << "实际的结果: "; 
	if( Find( num, ROW, COL, target ) )
		cout << "包含" << endl;
	else
		cout << "不包含" << endl;
}

void Test2()
{
	int num[ ROW ][ COL ] = { { 1, 2, 8, 9}, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	int target = 3;
	cout << "test2: 二维数组中不包含要查找的数字" << endl; 
	cout << "正确的结果: 不包含" << endl;
	cout << "实际的结果: "; 
	if( Find( num, ROW, COL, target ) )
		cout << "包含" << endl;
	else
		cout << "不包含" << endl;
}

void Test3()
{
	int num[ ROW ][ COL ] = {};
	int target = 3;
	cout << "test3: 特殊输入" << endl; 
	cout << "正确的结果: 不包含" << endl;
	cout << "实际的结果: "; 
	if( Find( num, ROW, COL, target ) )
		cout << "包含" << endl;
	else
		cout << "不包含" << endl;
}

int main()
{
	Test1();
	Test2();
	Test3();
	
	return 0;
}
