#include<iostream>
using namespace std;

bool Check( int row, int col, int limit )
{
	int sum = 0;
	while( row != 0 )
	{
		sum += row % 10;
		row /= 10;
	}
	while( col != 0 )
	{
		sum += col % 10;
		col /= 10;
	}
	return ( sum > limit ) ? false : true;
}

int FindAndMove( int rows, int cols, int row, int col, int count, int limit, bool * visited )
{
	if( row >= 0 && col >= 0 && row < rows && col < cols && limit >= 0 && Check( row, col, limit ) && !visited[ row * cols + col ] )
	{
		visited[ row * cols + col ] = true;
		count = 1 + FindAndMove( rows, cols, row, col - 1, count, limit, visited ) +
				FindAndMove( rows, cols, row, col + 1, count, limit, visited ) +
				FindAndMove( rows, cols, row - 1, col, count, limit, visited ) +
				FindAndMove( rows, cols, row + 1, col, count, limit, visited );
	}
	return count;
}

void SetFalse( bool * visited, int rows, int cols )
{
	for( int i = 0; i < rows * cols; i++ )
		visited[ i ] = false;
}

int MovingInMatrix( int rows, int cols, int limit )
{
	if( rows < 1 || cols < 1 || limit < 0 )
		return false;
	
	bool * visited = new bool[ rows * cols ];
	SetFalse( visited, rows, cols );
	
	int count = 0;
	count = FindAndMove( rows, cols, 0, 0, count, limit, visited );

	delete [] visited;
	return count;
}

void Test1()
{
	cout << "test1: 功能测试" << endl;
	int rows = 15, cols = 15, limit = 10;
	cout << "正常的输出: 169" << endl;
	cout << "实际的输出: " ;
	int count = MovingInMatrix( rows, cols, limit );
	cout << count << endl;
}

void Test2()
{
	cout << "test2: 边界值测试" << endl;
	int rows = 1, cols = 15, limit = 5;
	cout << "正常的输出: 6" << endl;
	cout << "实际的输出: " ;
	int count = MovingInMatrix( rows, cols, limit );
	cout << count << endl;
}

void Test3()
{
	cout << "test3: 特殊输入测试" << endl;
	int rows = 15, cols = 15, limit = -1;
	cout << "正常的输出: 0" << endl;
	cout << "实际的输出: " ;
	int count = MovingInMatrix( rows, cols, limit );
	cout << count << endl;
}

int main()
{
	Test1();
	Test2();
	Test3();
	
	return 0;
}
