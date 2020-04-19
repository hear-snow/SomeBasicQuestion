#ifndef STACKWITHMIN_H_
#define STACKWITHMIN_H_

#include<stack>
#include<cstdlib>
using namespace std;

template < typename T > class StackWithMin
{
private:
	stack< T > m_data;
	stack< T > m_min;
public:
	StackWithMin() {}
	~StackWithMin() {}
	void push( const T& );
	void pop();
	const T& min() const;
	const T& top() const;
	T& top();
};

template < typename T > void StackWithMin< T >::push( const T& value )
{
	m_data.push( value );
	
	if( m_min.empty() || value < m_min.top() )
		m_min.push( value );
	else
		m_min.push( m_min.top() );
}

template < typename T > void StackWithMin< T >::pop()
{
	if( m_data.empty() || m_min.empty() )
		abort();
	m_data.pop();
	m_min.pop();
}

template < typename T > const T& StackWithMin< T >::min() const
{
	if( m_data.empty() || m_min.empty() )
		abort();
	return m_min.top();
}

template < typename T > const T& StackWithMin< T >::top() const
{
	return m_data.top();
}

template < typename T > T& StackWithMin< T >::top()
{
	return m_data.top();
}

#endif
