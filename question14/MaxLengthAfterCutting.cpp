#include<iostream>
#include<cmath>
using namespace std;

int MaxLengthAfterCutting_1( int length )		//��̬�滮�� 
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

int MaxLengthAfterCutting_2( int length )		//̰���㷨 
{
	if( length < 2 )
		return 0;
	if( length == 2 )
		return 1;
	if( length == 3 )
		return 2;
		
	int cutNum_3 = length / 3;		//�����ܶ������Ϊ3�����Ӷ� 
	if( length - cutNum_3 * 3  == 1 )		//������ʣ�೤��Ϊ4�����Ϊ��������Ϊ2�Ķ� 
		cutNum_3--;
	int cutNum_2 = ( length - cutNum_3 * 3 ) / 2;
	return pow( 3, cutNum_3 ) * pow( 2, cutNum_2 );
}

void Test1()
{
	cout << "test1: ���ܲ���" << endl;
	cout << "��ȷ�����: 18" << endl; 
	int length = 8;
	int ans1 = MaxLengthAfterCutting_1( length );
	cout << "����һʵ�ʵ����: " << ans1 << endl; 
	int ans2 = MaxLengthAfterCutting_2( length );
	cout << "������ʵ�ʵ����: " << ans2 << endl; 
}

void Test2()
{
	cout << "test2: �߽�ֵ����" << endl;
	cout << "��ȷ�����: 2" << endl; 
	int length = 3;
	int ans1 = MaxLengthAfterCutting_1( length );
	cout << "����һʵ�ʵ����: " << ans1 << endl; 
	int ans2 = MaxLengthAfterCutting_2( length );
	cout << "������ʵ�ʵ����: " << ans2 << endl; 
}

int main()
{
	Test1();
	Test2();
	
	return 0;
}
