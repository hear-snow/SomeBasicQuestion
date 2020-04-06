#include<iostream>
#include<exception>
using namespace std;

int FindMinInNum( int Num[], int index1, int index2 )
{
	int temp = Num[ index1 ];
	for( int i = Num[ index1 + 1 ]; i < index2; i++ )
		if( Num[ i ] < temp )
			temp = Num[ i ];
	return temp;
}

int FindMin( int Num[], int length )
{
	if( Num == nullptr || length <= 0 )
		throw "Bad input";
	
	int index1 = 0;
	int index2 = length - 1;
	int indexMid = 0;
	
	while( Num[ index1 ] >= Num[ index2 ] )		//如果数组已经进行排序，则不进入循环，直接输出数组的第一个值 
	{
		if( index2 - index1 == 1 )
		{
			indexMid = index2;
			break;
		}
		indexMid = ( index1 + index2 ) / 2;
		if( Num[ index1 ] == Num[ indexMid ] && Num[ index2 ] == Num[ indexMid ] )		//如果三个值都相等，二分查找失效，只能顺序遍历 
			return FindMinInNum( Num, index1, index2 );	
		if( Num[ index1 ] <= Num[ indexMid ] )
			index1 = indexMid;
		else if( Num[ indexMid ] <= Num[ index2 ] )
			index2 = indexMid;
	}
	
	return Num[ indexMid ];
}

void Test1()
{
	int Num[] = { 3, 4, 5, 1, 2 };
	cout << "test1: 输入升序排序数组的一个旋转" << endl;
	cout << "正确的输出: 1" << endl;
	try
	{
		int MinNum = FindMin( Num, sizeof( Num ) / sizeof( int ) );
		cout << "实际的输出: " << MinNum << endl;
	}
	catch( const char * s )
	{
		cout << "实际的输出: " << s << endl;
	}
	
}

void Test2()
{
	int Num[] = { 1, 2, 3, 4, 5 };
	cout << "test2: 输入升序排序数组自身" << endl;
	cout << "正确的输出: 1" << endl;
	try
	{
		int MinNum = FindMin( Num, sizeof( Num ) / sizeof( int ) );
		cout << "实际的输出: " << MinNum << endl;
	}
	catch( const char * s )
	{
		cout << "实际的输出: " << s << endl;
	}
	
}

void Test3()
{
	int * Num = nullptr;
	cout << "test3: 不好的输入" << endl;
	cout << "正确的输出: Bad input" << endl;
	try
	{
		int MinNum = FindMin( Num, sizeof( Num ) / sizeof( int ) );
		cout << "实际的输出: " << MinNum << endl;
	}
	catch( const char * s )
	{
		cout << "实际的输出: " << s << endl;
	}
	
}

int main()
{
	Test1();
	Test2(); 
	Test3();
	
	return 0;
}
