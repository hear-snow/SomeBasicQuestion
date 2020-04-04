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
	cout << "test1: ��ά�����а���Ҫ���ҵ�����" << endl; 
	cout << "��ȷ�Ľ��: ����" << endl;
	cout << "ʵ�ʵĽ��: "; 
	if( Find( num, ROW, COL, target ) )
		cout << "����" << endl;
	else
		cout << "������" << endl;
}

void Test2()
{
	int num[ ROW ][ COL ] = { { 1, 2, 8, 9}, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	int target = 3;
	cout << "test2: ��ά�����в�����Ҫ���ҵ�����" << endl; 
	cout << "��ȷ�Ľ��: ������" << endl;
	cout << "ʵ�ʵĽ��: "; 
	if( Find( num, ROW, COL, target ) )
		cout << "����" << endl;
	else
		cout << "������" << endl;
}

void Test3()
{
	int num[ ROW ][ COL ] = {};
	int target = 3;
	cout << "test3: ��������" << endl; 
	cout << "��ȷ�Ľ��: ������" << endl;
	cout << "ʵ�ʵĽ��: "; 
	if( Find( num, ROW, COL, target ) )
		cout << "����" << endl;
	else
		cout << "������" << endl;
}

int main()
{
	Test1();
	Test2();
	Test3();
	
	return 0;
}
