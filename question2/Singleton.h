#ifndef SINGLETON_H_
#define SINGLETON_H_
#include <iostream>
using namespace std;

class Singleton
{
	private:
		static Singleton *s;
		Singleton() {}
		Singleton( const Singleton & ) {}
		~Singleton() {}
	public:
		static Singleton * Instance();
};

#endif
