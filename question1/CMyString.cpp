#include "CMyString.h"
#include <cstring>
#include <iostream>

CMyString::CMyString( char* pData )
{
	if( pData == nullptr )
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		m_pData = new char[ strlen( pData ) + 1 ];
		strcpy( m_pData, pData );
	}
}

CMyString::CMyString( const CMyString & str )
{
	m_pData = new char[ strlen( str.m_pData ) + 1 ];
	strcpy( m_pData, str.m_pData );
}

CMyString & CMyString::operator=( const CMyString & str )
{
	if( this != &str )
	{
		CMyString strTemp( str );
		char *pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}
	return *this;
}

ostream & operator<<( ostream & os, const CMyString & str )
{
	return os << str.m_pData;
}

CMyString::~CMyString( void )
{
	delete [] m_pData;
}
