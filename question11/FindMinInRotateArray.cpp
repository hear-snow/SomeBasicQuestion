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
	
	while( Num[ index1 ] >= Num[ index2 ] )		//��������Ѿ����������򲻽���ѭ����ֱ���������ĵ�һ��ֵ 
	{
		if( index2 - index1 == 1 )
		{
			indexMid = index2;
			break;
		}
		indexMid = ( index1 + index2 ) / 2;
		if( Num[ index1 ] == Num[ indexMid ] && Num[ index2 ] == Num[ indexMid ] )		//�������ֵ����ȣ����ֲ���ʧЧ��ֻ��˳����� 
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
	cout << "test1: �����������������һ����ת" << endl;
	cout << "��ȷ�����: 1" << endl;
	try
	{
		int MinNum = FindMin( Num, sizeof( Num ) / sizeof( int ) );
		cout << "ʵ�ʵ����: " << MinNum << endl;
	}
	catch( const char * s )
	{
		cout << "ʵ�ʵ����: " << s << endl;
	}
	
}

void Test2()
{
	int Num[] = { 1, 2, 3, 4, 5 };
	cout << "test2: ��������������������" << endl;
	cout << "��ȷ�����: 1" << endl;
	try
	{
		int MinNum = FindMin( Num, sizeof( Num ) / sizeof( int ) );
		cout << "ʵ�ʵ����: " << MinNum << endl;
	}
	catch( const char * s )
	{
		cout << "ʵ�ʵ����: " << s << endl;
	}
	
}

void Test3()
{
	int * Num = nullptr;
	cout << "test3: ���õ�����" << endl;
	cout << "��ȷ�����: Bad input" << endl;
	try
	{
		int MinNum = FindMin( Num, sizeof( Num ) / sizeof( int ) );
		cout << "ʵ�ʵ����: " << MinNum << endl;
	}
	catch( const char * s )
	{
		cout << "ʵ�ʵ����: " << s << endl;
	}
	
}

int main()
{
	Test1();
	Test2(); 
	Test3();
	
	return 0;
}
