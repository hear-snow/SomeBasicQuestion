#ifndef QUEUEWITHMAX_H_
#define QUEUEWITHMAX_H_

#include<deque>
#include<exception>
#include<iostream> 
using namespace std;

template< typename T > class QueueWithMax
{
private:
	struct InternalData
	{
		T number;
		int index;
	};
	deque< InternalData > data;
	deque< InternalData > maximums;
	int currentIndex;

public:
	QueueWithMax(): currentIndex( 0 )
	{
	}
	
	void push_back( T number )
	{
		while( !maximums.empty() && maximums.back().number <= number )
			maximums.pop_back();
		InternalData internalData = { number, currentIndex };
		data.push_back( internalData );
		maximums.push_back( internalData );
		++currentIndex;
	}
	
	void pop_front()
	{
		if( maximums.empty() )
			throw new exception( "queue is empty" );
		if( data.front().number == maximums.front().number )
			maximums.pop_front();
		data.pop_front();
	}
	
	T max() const
	{
		if( maximums.empty() )
			throw new exception( "queue is empty" );
		return maximums.front().number;
	}
};

#endif
