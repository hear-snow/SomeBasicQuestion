#include<iostream>
#include<stack>
using namespace std;

bool IsPopQueue( const int * numQueue1, const int * numQueue2, int length )
{
	bool flag = false;
	if( numQueue1 != nullptr && numQueue2 != nullptr && length > 0 )
	{
		const int * theNextPush = numQueue1;
		const int * theNextPop = numQueue2; 
		stack< int > data;
		while( theNextPop - numQueue2 < length )
		{
			while( data.empty() || data.top() != *theNextPop )
			{
				if( theNextPush - numQueue1 == length )
					break;
				data.push( *theNextPush );
				theNextPush++; 
			}
			
			if( data.top() != *theNextPop )
				break;
			
			data.pop();
			theNextPop++;
		}
		if( data.empty() && theNextPop - numQueue2 == length )
			flag = true;
	}
	return flag;
}

void Test1()
{
	int numQueue1[] = { 1, 2, 3, 4, 5 }, numQueue2[] = { 4, 5, 3, 2, 1 };
	bool ans = true;
	int length = sizeof( numQueue1 ) / sizeof( int );
	cout << "test1: ";
	if( IsPopQueue( numQueue1, numQueue2, length ) == ans )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

void Test2()
{
	int numQueue1[] = { 1, 2, 3, 4, 5 }, numQueue2[] = { 4, 3, 5, 1, 2 };
	bool ans = false;
	int length = sizeof( numQueue1 ) / sizeof( int );
	cout << "test2: ";
	if( IsPopQueue( numQueue1, numQueue2, length ) == ans )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

void Test3()
{
	bool ans = false;
	cout << "test3: ";
	if( IsPopQueue( nullptr, nullptr, 0 ) == ans )
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
