#include <iostream>
using namespace std; 


class Circle {
	int radius;

public:
    Circle(double r) : radius(r){}
    double area() 
		{ return radius * radius * 3.1415; }
};

    
class Cylinder {
	Circle base;
	double height;
	
	public:
	Cylinder(double r, double h):base(r), height(h){}
	double volume() 
		{ return base.area() * height; }	
};


int main() {
	Cylinder cyl(5, 8);
	cout << cyl.volume();
	
	return 0;
}
