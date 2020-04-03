#ifndef CMYSTRING_H_
#define CMYSTRING_H_
#include<iostream>
using std::ostream;

class CMyString
{
	public:
		CMyString( char* m_pData = nullptr );
		CMyString( const CMyString & str );
		CMyString & operator=( const CMyString & str );
		~CMyString( void );
		friend ostream & operator<<( ostream & os, const CMyString & str );
	private:
		char* m_pData;
};

#endif
