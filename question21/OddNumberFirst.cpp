#include<iostream>
using namespace std;

void OddNumberFirst( int * num, int length )
{
	if( num == nullptr || length <= 0 )
		return;
	int * pStart = num;
	int * pEnd = num + length - 1;
	while( pStart < pEnd )
	{
		while( pStart < pEnd && ( *pStart & 0x1 ) != 0 )
			pStart++;
		while( pStart < pEnd && ( *pEnd & 0x1 ) == 0 )
			pEnd--;
		if( pStart < pEnd )
		{
			int tmp = *pStart;
			*pStart = *pEnd;
			*pEnd = tmp;
		}
	}
}

void Test( int num[], int target[], int length )
{
	if( num == nullptr || target == nullptr )
		return;
	OddNumberFirst( num, length );
	bool flag = true;
	for( int i = 0; i < length; i++ )
		if( num[ i ] != target[ i ] )
			flag = false;
	if( flag )
		cout << "Passed" << endl;
	else
		cout << "Failed" << endl;
}

int main()
{
	int num[] = { 1, 2, 3, 4, 5 };
	int target[] = { 1, 5, 3, 4, 2 };
	int length = sizeof( num ) / sizeof( int );
	Test( num, target, length );
	
	return 0;
}
