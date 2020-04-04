#include<iostream>
using namespace std; 

int FindNum( const int *, int , int , int );

bool duplicate( const int num[], int length, int * duplication )
{
	if( num == nullptr || length <= 0 )
		return false;
		
	for( int i = 0; i < length; i++ )
	{
		if( num[ i ] < 0 || num[ i ] > length - 1 )
			return false;
	}
	
	int begin = 0, end = length - 1;
	while( end >= begin )
	{
		int middle = ( end + begin ) / 2;
		int count = FindNum( num, length, begin, middle );
		if( end == begin )
		{
			if( count > 1 )
			{
				*duplication = begin;
				return true;
			}
			else
				return false; 
		}
		if( count > ( middle - begin + 1 ) )
			end = middle;
		else
			begin = middle + 1;
	}
	
	return false;
}

int FindNum( const int num[], int length, int begin, int end )
{
	int count = 0;
	for( int i = 0; i < length; i++ )
		if( num[ i ] >= begin && num[ i ] <= end )
			count++;
	return count;
}

void Test1()
{
	int num[] = { 2, 3, 1, 0, 2, 5, 4 };
	int duplication;
	
	cout << "test1: ���������ظ�ֵ" << endl;
	cout << "���������: 2" << endl; 
	cout << "ʵ�ʵ����: "; 
	if( duplicate( num, sizeof( num ) / sizeof( int ), &duplication ) )
		cout << duplication << endl;
	else
		cout << "û���ظ�ֵ"  << endl;
}

void Test2()
{
	int num[] = { 0, 3, 2, 4, 1, 5 };
	int duplication;
	
	cout << "test2: ������û���ظ�ֵ" << endl;
	cout << "���������: û���ظ�ֵ" << endl; 
	cout << "ʵ�ʵ����: "; 
	if( duplicate( num, sizeof( num ) / sizeof( int ), &duplication ) )
		cout << duplication << endl;
	else
		cout << "û���ظ�ֵ"  << endl;
}

void Test3()
{
	int num[] = { 1, -6, 5, 0, 2, 4, 3, 1 };
	int duplication;
	
	cout << "test3: ��Ч������" << endl;
	cout << "���������: û���ظ�ֵ" << endl; 
	cout << "ʵ�ʵ����: "; 
	if( duplicate( num, sizeof( num ) / sizeof( int ), &duplication ) )
		cout << duplication << endl;
	else
		cout << "û���ظ�ֵ"  << endl;
}

int main()
{
	Test1();
	Test2();
	Test3();
		
	return 0;
} 
