#include<iostream>
#include<cmath>
using namespace std;

int MaxLengthAfterCutting_1( int length )		//动态规划法 
{
	if( length < 2 )
		return 0;
	if( length == 2 )
		return 1;
	if( length == 3 )
		return 2;
	
	int * lengthAns = new int[ length + 1 ];
	lengthAns[ 0 ] = 0;
	lengthAns[ 1 ] = 1;
	lengthAns[ 2 ] = 2;
	lengthAns[ 3 ] = 3;
	int max = 0;
	for( int i = 4; i <= length; i++ )
	{
		max = 0;
		for( int j = 1; j <= i / 2; j++ )
		{
			int cuttingLength = lengthAns[ j ] * lengthAns[ i - j ];
			if( max < cuttingLength )
				max = cuttingLength;
		}
		lengthAns[ i ] = max;
	}
	max = lengthAns[ length ];
	delete [] lengthAns;
	return max;
}

int MaxLengthAfterCutting_2( int length )		//贪婪算法 
{
	if( length < 2 )
		return 0;
	if( length == 2 )
		return 1;
	if( length == 3 )
		return 2;
		
	int cutNum_3 = length / 3;		//尽可能多剪长度为3的绳子段 
	if( length - cutNum_3 * 3  == 1 )		//如果最后剩余长度为4，则剪为两个长度为2的段 
		cutNum_3--;
	int cutNum_2 = ( length - cutNum_3 * 3 ) / 2;
	return pow( 3, cutNum_3 ) * pow( 2, cutNum_2 );
}

void Test1()
{
	cout << "test1: 功能测试" << endl;
	cout << "正确的输出: 18" << endl; 
	int length = 8;
	int ans1 = MaxLengthAfterCutting_1( length );
	cout << "方法一实际的输出: " << ans1 << endl; 
	int ans2 = MaxLengthAfterCutting_2( length );
	cout << "方法二实际的输出: " << ans2 << endl; 
}

void Test2()
{
	cout << "test2: 边界值测试" << endl;
	cout << "正确的输出: 2" << endl; 
	int length = 3;
	int ans1 = MaxLengthAfterCutting_1( length );
	cout << "方法一实际的输出: " << ans1 << endl; 
	int ans2 = MaxLengthAfterCutting_2( length );
	cout << "方法二实际的输出: " << ans2 << endl; 
}

int main()
{
	Test1();
	Test2();
	
	return 0;
}
