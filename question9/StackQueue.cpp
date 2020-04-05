#include<iostream>
#include<stack>
#define MAX 5
using namespace std;

template< typename T > class CQueue
{
	public:
		CQueue( void ) {};
		~CQueue( void );
		void appendTail( const T& node );
		T deleteHead();
	private:
		stack< T > stack1;
		stack< T > stack2;	
};

template< typename T > CQueue< T >::~CQueue()
{
	while( !stack1.empty() )
		stack1.pop();
	while( !stack2.empty() )
		stack2.pop();
}

template< typename T > void CQueue< T >::appendTail( const T& node )
{
	stack1.push( node );
}

template< typename T > T CQueue< T >::deleteHead()
{
	if( stack2.empty() )
		while( !stack1.empty() )
		{
			T node = stack1.top();
			stack2.push( node );
			stack1.pop();
		}
	if( stack2.empty() )
		throw "queue is empty";
	T temp = stack2.top();
	stack2.pop();
	return temp;
}

void Test1()
{
	cout << "test1: ���������ӡ�ɾ��Ԫ��" << endl; 
	CQueue< int > mQueue;
	for( int i = 1; i <= MAX; i++ ) 
		mQueue.appendTail( i );
	
	cout << "��ȷ�����: ";
	for( int i = 1; i <= MAX; i++ ) 
		cout << i << ' ';
	cout << endl;
	
	cout << "ʵ�ʵ����: ";
	try
	{
		for( int i = 1; i <= MAX; i++ ) 
			cout << mQueue.deleteHead() << ' ';
	}
	catch( const char * s )
	{
		cout << s << endl;
	}
	cout << endl;
}

void Test2()
{
	cout << "test2: ɾ������ֱ������Ϊ��" << endl; 
	CQueue< int > mQueue;
	for( int i = 1; i <= MAX; i++ ) 
		mQueue.appendTail( i );
	
	cout << "��ȷ�����: ";
	for( int i = 1; i <= MAX; i++ ) 
		cout << i << ' ';
	cout << "queue is empty" << endl;
	
	cout << "ʵ�ʵ����: ";
	try
	{
		for( int i = 1; i <= MAX + 1; i++ ) 
			cout << mQueue.deleteHead() << ' ';
	}
	catch( const char * s )
	{
		cout << s << endl;
	}
}

int main()
{
	Test1();
	Test2();
	
	return 0;
}
