#include<iostream>
#include<stack>
using namespace std;

bool IsBinarySearchTreeBackwardOrder( int * data, int length )
{
	if( data == nullptr || length <= 0 )
		return false;
	int treeRoot = data[ length - 1 ];
	int i = 0;
	for( ; i < length - 1; i++ )
		if( data[ i ] > treeRoot )
			break;
	for( int j = i; j < length - 1; j++ )
		if( data[ j ] < treeRoot )
			return false;
	bool leftFlag = true, rightFlag = true;
	if( i > 0 )
		leftFlag = IsBinarySearchTreeBackwardOrder( data, i );
	if( i < length - 1 )
		rightFlag = IsBinarySearchTreeBackwardOrder( data + i, length - i - 1 );
	return leftFlag && rightFlag;
}

void Test1()
{
	cout << "test1: ���ܲ���" << endl; 
	cout << "���������: Passed!" << endl;
	int data[] = { 5, 7, 6, 9, 11, 10, 8 };
	cout << "ʵ�ʵ����: ";
	if( IsBinarySearchTreeBackwardOrder( data, sizeof( data ) / sizeof ( int ) ) )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

void Test2()
{
	cout << "test2: ���ܲ���" << endl; 
	cout << "���������: Failed!" << endl;
	int data[] = { 10, 8, 6, 7, 4, 2 };
	cout << "ʵ�ʵ����: ";
	if( IsBinarySearchTreeBackwardOrder( data, sizeof( data ) / sizeof ( int ) ) )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

void Test3()
{
	cout << "test3: �������" << endl; 
	cout << "���������: Failed!" << endl;
	int * data = nullptr; 
	cout << "ʵ�ʵ����: ";
	if( IsBinarySearchTreeBackwardOrder( data, sizeof( data ) / sizeof ( int ) ) )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	Test1();
	Test2();
	Test3();
	
	return 0;
}
