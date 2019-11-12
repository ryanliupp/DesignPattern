#ifndef OBSERVERPATTERN
#define OBSERVERPATTERN
#include <string>
#include <iostream>
#include <vector>
using namespace std;
struct Subject;
struct Observer
{
	virtual void update(){};
	Subject* sub;
	
};
struct Subject
{
	
	int getstate(){ return state; };
	void setstate(int state){ this->state = state; notifyAllObservers(); };
	void attach(Observer* addobser){ obsvector.push_back(addobser); };
	void notifyAllObservers()
	{
		for (int i = 0; i < obsvector.size(); i++){
			obsvector[i]->update();
		}
	};
private:
	vector<Observer*> obsvector;
	int state;
};
struct Aobserver:public Observer
{
	Aobserver(Subject* subject)
	{
		this->sub = subject;
		subject->attach(this);
	}
	void update(){
		cout << "A observer has known!" << endl;
	};
};
struct Bobserver :public Observer
{
	Bobserver(Subject* subject)
	{
		this->sub = subject;
		subject->attach(this);
	}
	void update()
	{
		cout << "B observer has known!" << endl;
	};
};



#endif