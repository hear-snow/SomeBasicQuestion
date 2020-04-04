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
	cout << "test1: 输入的字符串中包含空格" << endl; 
	cout << "正确的输出: We%20are%20happy." << endl;
	Replacement( text, strlen( text ) );
	cout << "实际的输出: " << text << endl;
}

void Test2()
{
	char text[ MAX ] = "Wearehappy.";
	cout << "test2: 输入的字符串中不包含空格" << endl; 
	cout << "正确的输出: Wearehappy." << endl;
	Replacement( text, strlen( text ) );
	cout << "实际的输出: " << text << endl;
}

void Test3()
{
	char text[ MAX ] = {};
	cout << "test3: 特殊的输入" << endl; 
	cout << "正确的输出: " << endl;
	Replacement( text, strlen( text ) );
	cout << "实际的输出: " << text << endl;
}

void Test4()
{
	char text[ MAX ] = "We   are   happy.";
	cout << "test4: 特殊的输入" << endl; 
	cout << "正确的输出: We%20%20%20are%20%20%20happy." << endl;
	Replacement( text, strlen( text ) );
	cout << "实际的输出: " << text << endl;
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	
	return 0;
}
