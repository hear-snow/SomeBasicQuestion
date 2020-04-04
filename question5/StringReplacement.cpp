#include<iostream>
#include<cstring>
#define MAX 40
using namespace std;

void Replacement( char * text, int length )
{
	if( text == nullptr || length == 0 )
		return;
	
	int p1, p2, count = 0;
	for( int i = 0; i < length; i++ )
		if( text[ i ] == ' ' )
			count++;
	p1 = length + 1;
	p2 = length + 1 + count * 2;
	
	if( p2 > MAX )
		return;
	
	while( p1 != p2 )
	{
		if( text[ p1 ] == ' ' )
		{
			text[ p2-- ] = '0';
			text[ p2-- ] = '2';
			text[ p2-- ] = '%';
		}
		else
			text[ p2-- ] = text[ p1 ];
		p1--;
	}
}

void Test1()
{
	char text[ MAX ] = "We are happy.";
	cout << "test1: ������ַ����а����ո�" << endl; 
	cout << "��ȷ�����: We%20are%20happy." << endl;
	Replacement( text, strlen( text ) );
	cout << "ʵ�ʵ����: " << text << endl;
}

void Test2()
{
	char text[ MAX ] = "Wearehappy.";
	cout << "test2: ������ַ����в������ո�" << endl; 
	cout << "��ȷ�����: Wearehappy." << endl;
	Replacement( text, strlen( text ) );
	cout << "ʵ�ʵ����: " << text << endl;
}

void Test3()
{
	char text[ MAX ] = {};
	cout << "test3: ���������" << endl; 
	cout << "��ȷ�����: " << endl;
	Replacement( text, strlen( text ) );
	cout << "ʵ�ʵ����: " << text << endl;
}

void Test4()
{
	char text[ MAX ] = "We   are   happy.";
	cout << "test4: ���������" << endl; 
	cout << "��ȷ�����: We%20%20%20are%20%20%20happy." << endl;
	Replacement( text, strlen( text ) );
	cout << "ʵ�ʵ����: " << text << endl;
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	
	return 0;
}
