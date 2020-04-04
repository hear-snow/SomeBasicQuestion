#include<iostream>
using namespace std; 

bool duplicate( int num[], int length, int * duplication )
{
	if( num == nullptr || length <= 0 )
		return false;
		
	for( int i = 0; i < length; i++ )
	{
		if( num[ i ] < 0 || num[ i ] >= length )
			return false;
	}
	
	for( int i = 0; i < length; i++ )
	{
		while( num[ i ] != i )
		{
			if( num[ i ] == num[ ( num[ i ] ) ] )
			{
				*duplication = num[ i ];
				return true;
			}
			else
			{
				int temp = num[ i ];
				num[ i ] = num[ temp ];
				num[ temp ] = temp;
			}
		}
	}
	return false;
} 

void Test1()
{
	int num[] = { 2, 3, 1, 0, 2, 5, 4 };
	int duplication;
	
	cout << "test1: 数组中有重复值" << endl;
	cout << "正常的输出: 2" << endl; 
	cout << "实际的输出: "; 
	if( duplicate( num, sizeof( num ) / sizeof( int ), &duplication ) )
		cout << duplication << endl;
	else
		cout << "没有重复值"  << endl;
}

void Test2()
{
	int num[] = { 0, 3, 2, 4, 1, 5 };
	int duplication;
	
	cout << "test2: 数组中没有重复值" << endl;
	cout << "正常的输出: 没有重复值" << endl; 
	cout << "实际的输出: "; 
	if( duplicate( num, sizeof( num ) / sizeof( int ), &duplication ) )
		cout << duplication << endl;
	else
		cout << "没有重复值"  << endl;
}

void Test3()
{
	int num[] = { 1, -6, 5, 0, 2, 4, 3, 1 };
	int duplication;
	
	cout << "test3: 无效的输入" << endl;
	cout << "正常的输出: 没有重复值" << endl; 
	cout << "实际的输出: "; 
	if( duplicate( num, sizeof( num ) / sizeof( int ), &duplication ) )
		cout << duplication << endl;
	else
		cout << "没有重复值"  << endl;
}

int main()
{
	Test1();
	Test2();
	Test3();
		
	return 0;
} 
