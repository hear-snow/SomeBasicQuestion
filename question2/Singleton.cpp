#include "Singleton.h"

Singleton * Singleton::s = nullptr;

Singleton * Singleton::Instance()
{
	if( s == nullptr )
		s = new Singleton;
	return s;
}
