#include<iostream>
using namespace std;

int NumberOfOne_1( int num )
{
	int count = 0;
	unsigned int temp = 1;
	while( temp )
	{
		if( num & temp )
			count++;
		temp = temp << 1;
	}
	return count;
}

int NumberOfOne_2( int num )
{
	int count = 0;
	while( num )
	{
		num = num & ( num - 1 );
		count++;
	}
	return count;
}

void Test1()
{
	cout << "test1: ��������" << endl;
	cout << "���������: 2" << endl; 
	int num = 12;
	int count1 = NumberOfOne_1( num ); 
	cout << "����һʵ�ʵ����: " << count1 << endl; 
	int count2 = NumberOfOne_2( num ); 
	cout << "������ʵ�ʵ����: " << count2 << endl; 
}

void Test2()
{
	cout << "test2: ��������" << endl;
	cout << "���������: 32" << endl; 
	int num = 0xFFFFFFFF;
	int count1 = NumberOfOne_1( num ); 
	cout << "����һʵ�ʵ����: " << count1 << endl; 
	int count2 = NumberOfOne_2( num ); 
	cout << "������ʵ�ʵ����: " << count2 << endl; 
}

void Test3()
{
	cout << "test3: �����������" << endl;
	cout << "���������: 0" << endl; 
	int num = 0;
	int count1 = NumberOfOne_1( num ); 
	cout << "����һʵ�ʵ����: " << count1 << endl; 
	int count2 = NumberOfOne_2( num ); 
	cout << "������ʵ�ʵ����: " << count2 << endl; 
}

int main()
{
	Test1();
	Test2(); 
	Test3(); 
	
	return 0;
}
