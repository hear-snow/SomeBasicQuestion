#include<iostream>
using namespace std;

bool FindWord( char * matrix, int rows, int cols, int row, int col, char * target, int wordLength, bool * visited )
{
	if( target[ wordLength ] == '\0' )
		return true;
	
	bool IsFind = false;
	if( row >= 0 && col >= 0 && row < rows && col < cols && matrix[ row * cols + col ] == target[ wordLength ] && !visited[ row * cols + col ] )
	{
		wordLength++;
		visited[ row * cols + col ] = true;
		IsFind = FindWord( matrix, rows, cols, row, col - 1, target, wordLength, visited ) ||
				 FindWord( matrix, rows, cols, row, col + 1, target, wordLength, visited ) ||
				 FindWord( matrix, rows, cols, row - 1, col, target, wordLength, visited ) ||
				 FindWord( matrix, rows, cols, row + 1, col, target, wordLength, visited );
		if( !IsFind )
		{
			wordLength--;
			visited[ row * cols + col ] = false;
		}
	}
	return IsFind;
}

void SetFalse( bool * visited, int rows, int cols )
{
	for( int i = 0; i < rows * cols; i++ )
		visited[ i ] = false;
}

bool FindWordInMatrix( char * matrix, int rows, int cols, char * target )
{
	if( matrix == nullptr || rows < 1 || cols < 1 || target == nullptr )
		return false;
	
	bool * visited = new bool[ rows * cols ];
	SetFalse( visited, rows, cols );
	
	int wordLength = 0;
	for( int row = 0; row < rows; row++ )
		for( int col = 0; col < cols; col++ )
		{
			if( FindWord( matrix, rows, cols, row, col, target, wordLength, visited ) )
			{
				delete [] visited;
				return true;				
			}
		}
	delete [] visited;
	return false;
}

void Test1()
{
	cout << "test1: 功能测试" << endl;
	char matrix[] = { 'a', 'b', 't', 'g', 'c', 'f', 'c', 's', 'j', 'd', 'e', 'h' };
	int rows = 3, cols = 4;
	char target[] = "bfce";
	cout << "正常的输出: true" << endl;
	cout << "实际的输出: " ;
	if( FindWordInMatrix( matrix, rows, cols, target ) )
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

void Test2()
{
	cout << "test2: 边界值测试" << endl;
	char matrix[] = { 'a', 'b', 't', 'g' };
	int rows = 1, cols = 4;
	char target[] = "btc";
	cout << "正常的输出: false" << endl;
	cout << "实际的输出: " ;
	if( FindWordInMatrix( matrix, rows, cols, target ) )
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

void Test3()
{
	cout << "test3: 特殊输入测试" << endl;
	char * matrix = nullptr;
	int rows = 0, cols = 0;
	char target[] = "cd";
	cout << "正常的输出: false" << endl;
	cout << "实际的输出: " ;
	if( FindWordInMatrix( matrix, rows, cols, target ) )
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

int main()
{
	Test1();
	Test2();
	Test3();
	
	return 0;
}
