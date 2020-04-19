#include "StackWithMin.h"
#include<iostream>
using namespace std;

void Test( const char * str, const StackWithMin< int > & stack, int ans )
{
	if( str != nullptr )
		cout << str << ": ";
	if( ans == stack.min() )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	StackWithMin< int > stack;
	stack.push( 2 );
	Test( "test1", stack, 2 );
	
	stack.push( 5 );
	Test( "test2", stack, 2 );
	
	stack.push( 1 );
	Test( "test3", stack, 1 );
	
	stack.pop();
	Test( "test4", stack, 2 );
	
	stack.pop();
	Test( "test5", stack, 2 );
	
	stack.push( 0 );
	Test( "test6", stack, 0 );
	
	return 0;
}
