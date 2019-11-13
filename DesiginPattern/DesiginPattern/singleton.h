#ifndef SINGLETON
#define SINGLETON
#include <iostream>
struct lazySingleton
{
	static lazySingleton* getSingleton(){
		if (singletonInstance == nullptr){
			singletonInstance =  new lazySingleton();
			return singletonInstance;
		}
		else
			return singletonInstance;
	};
private:
	lazySingleton();
	static lazySingleton* singletonInstance;
};




#endif