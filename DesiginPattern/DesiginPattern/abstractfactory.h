#include <string>
#include <iostream>
#ifndef ABSTRACTFACTORY
#define ABSTRACTFACTORY
using namespace std;
struct fruit
{
	virtual void getfruit() = 0;
};
struct apple :public fruit
{
	void getfruit(){ cout << "apple eat" << endl; };
	
};
struct pear :public fruit
{
	void getfruit(){ cout << "pear eat" << endl; };
};

struct tea
{
	virtual void gettea() = 0;
};

struct oolong :public tea
{
	void gettea(){ cout << "oolong tea" << endl; };

};

struct guanyin :public tea
{
	void gettea(){ cout << "guanyin tea" << endl; };

};

struct abstructfactory
{
	virtual tea& getteaa() = 0;
	virtual fruit& getfruita() = 0;
};
struct teaFactory : public abstructfactory
{
	tea& gettea(){ return new oolong(); };
	fruit& getfruit(){ return new apple(); };
};



#endif