#include<iostream>
#define NUMBER 10
using namespace std;

//方法一：构造函数 
class Temp
{
public:
	Temp() { ++N; Sum += N; }
	static void Reset() { N = 0; Sum = 0; }
	static unsigned int GetSum() { return Sum; }
private:
	static unsigned int N;
	static unsigned int Sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

void Sum_Solution1( unsigned int n )
{
	Temp::Reset();
	Temp * a = new Temp[ n ];
	delete [] a;
	cout << "Solution1: " << Temp::GetSum() << endl;
}

//方法二：虚函数
class A;
A * Array[ 2 ];

class A
{
public:
	virtual unsigned int Sum( unsigned int n )
	{
		return 0;
	}
};

class B : public A
{
public:
	virtual unsigned int Sum( unsigned int n )
	{
		return Array[ !!n ]->Sum( n - 1 ) + n;
	}
};

void Sum_Solution2( unsigned int n )
{
	A a;
	B b;
	Array[ 0 ] = &a;
	Array[ 1 ] = &b;
	cout << "Solution2: " << Array[ 1 ]->Sum( n ) << endl;
}

//方法三：函数指针
typedef unsigned int ( *fun  )( unsigned int );

unsigned int Sum_Teminator( unsigned int n )
{
	return 0;
}

unsigned int Sum_Loop( unsigned int n )
{
	static fun f[ 2 ] = { Sum_Teminator, Sum_Loop };
	return f[ !!n ]( n - 1 ) + n;
}

void Sum_Solution3( unsigned int n )
{
	cout << "Solution3: " << Sum_Loop( n ) << endl;
}

//方法四：模板类
template< unsigned int n > struct Sum_Struct
{
	enum Value { N = Sum_Struct< n - 1 >::N + n };
};

template<> struct Sum_Struct< 1 >
{
	enum Value { N = 1 };
};

void Sum_Solution4( unsigned int n )
{
	cout << "Solution4: " << Sum_Struct< NUMBER >::N << endl;
}

int main()
{
	Sum_Solution1( NUMBER );
	Sum_Solution2( NUMBER );
	Sum_Solution3( NUMBER );
	Sum_Solution4( NUMBER );
	
	return 0;
}
