#include "factorymode.h"

int main()
{
	HumanFactory* factory = new HumanFactory();
	human* test = factory->createHuman("male");
	test->eat();
	test->sleep();
	test = factory->createHuman("female");
	test->eat();
	test->sleep();
	return 0;
}