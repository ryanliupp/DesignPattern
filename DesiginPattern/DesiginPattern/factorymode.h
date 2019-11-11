
#ifndef FACTORYMODE
#define FACTORYMODE
#include <string>
#include <iostream>
using namespace std;
struct human
{
	virtual void eat() = 0;
	virtual void sleep() = 0;
	virtual void beat() = 0;
};
struct Male :public human
{
	void eat(){ cout << "male eat" << endl; };
	void sleep(){ cout << "male sleep" << endl; };
	void beat(){ cout << "male beat" << endl; };
};
struct Female :public human
{
	void eat(){ cout << "female eat" << endl; };
	void sleep(){ cout << "female sleep" << endl; };
	void beat(){ cout << "female beat" << endl; };
};
struct HumanFactory
{
	human* createHuman(string humankind){
		if (humankind == "male"){
			return new Male;
		}
		else if (humankind == "female"){
			return new Female;
		}
	};
};



#endif