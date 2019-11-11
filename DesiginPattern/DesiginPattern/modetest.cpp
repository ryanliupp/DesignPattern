#include "factorymode.h"
#include "abstractfactory.h"
#include "AdapterPattern.h"
void test3();
int main()
{
	
	test3();
	return 0;
	
	
	
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
