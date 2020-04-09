#include<iostream>
#include<cstring>
using namespace std;

void SetZeros( char * numbers, int length )
{
	for( int i = 0; i < length; ++i )
		numbers[ i ] = '0';
}

bool IncreaseNumbers( char * numbers )
{
	bool isOver = false;
	int takeOver = 0;
	int length = strlen( numbers );
	for( int i = length - 1; i >= 0; i-- )
	{
		int num = numbers[ i ] - '0' + takeOver;
		if( i == length - 1 )
			num++;
		if( num >= 10 )
		{
			if( i == 0 )
				isOver = true;
			else
			{
				takeOver = 1;
				num -= 10;
				numbers[ i ] = num + '0';	//���������λ�����ܽ���break����Ҫһֱ��λֱ���ҵ�һ�������λ��λ 
			}
		}
		else
		{
			numbers[ i ] = num + '0';
			break;
		}
	}
	return isOver;
}

void PrintNumbers( char * numbers )
{
	bool isZeroInBegin = true;
	int length = strlen( numbers );
	for( int i = 0; i < length; ++i )
	{
		if( isZeroInBegin && numbers[ i ] != '0' )
			isZeroInBegin = false;
		if( !isZeroInBegin )
			cout << numbers[ i ];
	}
	if( isZeroInBegin )
		return;
	cout << '\t';
} 

void Print1ToNDigits_1( int digits )
{
	if( digits <= 0 )
		return;
	char * numbers = new char[ digits + 1 ];	//�����ַ��� 
	SetZeros( numbers, digits );
	numbers[ digits ] = '\0';
	
	while( !IncreaseNumbers( numbers ) )
		PrintNumbers( numbers );
	
	delete [] numbers;
} 

void Print1ToNDigits_Process( char * numbers, int length, int location )
{
	if( location == length - 1 )
	{
		PrintNumbers( numbers );
		return;
	}
	for( int i = 0; i < 10; ++i )
	{
		numbers[ location + 1 ] = i + '0';
		Print1ToNDigits_Process( numbers, length, location + 1 );
	}
}

void Print1ToNDigits_2( int digits )
{
	if( digits <= 0 )
		return;
	char * numbers = new char[ digits + 1 ];
	numbers[ digits ] = '\0';
	
	for( int i = 0; i < 10; ++i )
	{
		numbers[ 0 ] = i + '0';
		Print1ToNDigits_Process( numbers, digits, 0 );
	}
	delete [] numbers;
} 

void Test1()
{
	cout << "���ܲ���" << endl;
	int digits = 2;
	cout << "����һ���: " << endl;
	Print1ToNDigits_1( digits ); 
	cout << endl;
	cout << "���������: " << endl;
	Print1ToNDigits_2( digits ); 
	cout << endl;
}

void Test2()
{
	cout << "�������" << endl;
	int digits = -1;
	cout << "����һ���: " << endl;
	Print1ToNDigits_1( digits ); 
	cout << endl;
	cout << "���������: " << endl;
	Print1ToNDigits_2( digits ); 
	cout << endl;
}

int main()
{
	Test1();
	Test2();
	
	return 0;
}
