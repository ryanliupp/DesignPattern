#include "factorymode.h"
#include "abstractfactory.h"
#include "AdapterPattern.h"
#include "DecoratorPattern.h"
#include "observerpattern.h"
#include "singleton.h"
void test3();
void test4();
void test5();
void test6();
int main()
{
	test6();
	return 0;
	
}
void test6()
{
	//lazySingleton* test1 = new lazySingleton();
	lazySingleton* oneInstance = lazySingleton::getSingleton();
	lazySingleton* anotherInstance = lazySingleton::getSingleton();
	delete oneInstance;
}
void test5()
{
	Subject *sub = new Subject();
	Observer *Aobser = new Aobserver(sub);
	Observer *Bobser = new Bobserver(sub);
	sub->setstate(0);
	sub->setstate(1);
	delete sub;
	delete Aobser;
	delete Bobser;
}
void test4()
{
	Circle *fivecircle = new Circle();
	Rectangle *rectdemo = new Rectangle();
	fivecircle->draw();
	RedShapeDecorator *redcircle = new RedShapeDecorator(fivecircle);
	RedShapeDecorator *redrect = new RedShapeDecorator(rectdemo);
	redcircle->draw();
	rectdemo->draw();
	redrect->draw();
	delete fivecircle;
	delete rectdemo;
	delete redcircle;
	delete redrect;
}
void test3()
{
	HumanPlayer *aman = new HumanPlayer();
	AudioPlay *ipod3 = new AudioPlay();
	aman->play(ipod3, "MP4");
	vlcMediaPlay *ipodvlc = new vlcMediaPlay();
	mp4MediaPlay *ipodmp4 = new mp4MediaPlay();
	MediaAdapter *ipod3to4 = new MediaAdapter(ipodmp4);
	aman->play(ipod3to4,"mp4");
	ipod3to4->changeAdapater(ipodvlc);
	aman->play(ipod3to4, "vlc");
	delete aman;
	delete ipod3;
	delete ipodvlc;
	delete ipodmp4;
	delete ipod3to4;
}
void test2()
{
	teaFactory test;
	(test.getfruita())->getfruit();
	test.getteaa()->gettea();
}
void test1()
{
	HumanFactory* factory = new HumanFactory();
	human* test = factory->createHuman("male");
	test->eat();
	test->sleep();
	test = factory->createHuman("female");
	test->eat();
	test->sleep();
}
