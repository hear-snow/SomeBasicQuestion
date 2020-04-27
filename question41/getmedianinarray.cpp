#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

template < typename T > class DynamicArray
{
public:
	void Insert( T num )
	{
		if( ( ( max.size() + min.size() ) & 1 ) == 0 )
		{
			if( max.size() > 0 && num < max[ 0 ] )
			{
				max.push_back( num );
				push_heap( max.begin(), max.end(), less< T >() );
				num = max[ 0 ];
				pop_heap( max.begin(), max.end(), less< T >() );
				max.pop_back();
			}
			min.push_back( num );
			push_heap( min.begin(), min.end(), greater< T >() );
		}
		else
		{
			if( min.size() > 0 && num > min[ 0 ] )
			{
				min.push_back( num );
				push_heap( min.begin(), min.end(), greater< T >() );
				num = min[ 0 ];
				pop_heap( min.begin(), min.end(), greater< T >() );
				min.pop_back();
			}
			max.push_back( num );
			push_heap( max.begin(), max.end(), less< T >() );
		}
	}
	T GetMedian()
	{
		int size = min.size() + max.size();
		T median = 0;
		if( size & 1 )
			median = min[ 0 ];
		else
			median = ( max[ 0 ] + min[ 0 ] ) / 2;
		return median;
	}
private:
	vector< T > max;
	vector< T > min;
};

void Test( const char * str, DynamicArray< double > & numbers, double ans )
{
	cout << str << ": ";
	if( ( numbers.GetMedian() - ans > -0.0000001 ) && ( numbers.GetMedian() - ans < 0.0000001 ) )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl; 
}

int main()
{
	DynamicArray< double > numbers;
	numbers.Insert( 5 );
	Test( "test1", numbers, 5 );
	
	numbers.Insert( 2 );
	Test( "test2", numbers, 3.5 );
	
	numbers.Insert( 3 );
	Test( "test3", numbers, 3 );
	
	numbers.Insert( 4 );
	Test( "test4", numbers, 3.5 );
	
	numbers.Insert( 1 );
	Test( "test5", numbers, 3 );
	
	numbers.Insert( 6 );
	Test( "test6", numbers, 3.5 );
	
}
