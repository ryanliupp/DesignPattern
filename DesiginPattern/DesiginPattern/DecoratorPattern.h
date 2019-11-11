#ifndef DECORATORPATTERN
#define DECORATORPATTERN
#include <iostream>
using namespace std;
struct Shape
{
	virtual void draw() = 0;
	virtual ~Shape(){};
};

struct Circle:public Shape
{
	void draw(){ cout << "draw a circle" << endl; }
};

struct Rectangle :public Shape
{
	void draw(){ cout << "draw a rectangle" << endl; }
};

struct ShapeDecorator:public Shape
{
	Shape* shape;
	ShapeDecorator(Shape* shape){ this->shape = shape; };
	void draw(){};
	virtual ~ShapeDecorator(){};
};

struct RedShapeDecorator:public ShapeDecorator
{
	RedShapeDecorator(Shape* shape) :ShapeDecorator(shape){};
	void draw()
	{
		setRedBorder(shape);
		shape->draw();
		
	};
	void setRedBorder(Shape* shape){ cout << "color is: red and than "; };
};

#endif