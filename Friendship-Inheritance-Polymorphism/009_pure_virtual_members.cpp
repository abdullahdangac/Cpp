// pure virtual members can be called
// from the abstract base class
#include <iostream>
using namespace std;


class Polygon {
  protected:
    int width, height;
  public:
    void set_values(int a, int b)
      	{ width = a; height = b; }
    virtual int area() = 0;
    void print_area()
      	{ cout << this->area() << '\n'; }
};


class Rectangle: public Polygon {
  public:
    int area(void)
      	{ return (width * height); }
};


class Triangle: public Polygon {
  public:
    int area(void)
      	{ return (width * height / 2); }
};


int main () {
  	Rectangle rect;
  	Triangle trgl;
  
  	Polygon* ppoly1 = &rect;
  	Polygon* ppoly2 = &trgl;
  
  	ppoly1->set_values (4, 5);
  	ppoly2->set_values (4, 5);
  
  	ppoly1->print_area();
  	ppoly2->print_area();
  
  	return 0;
}
