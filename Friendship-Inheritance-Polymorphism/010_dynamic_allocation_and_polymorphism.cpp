// dynamic allocation and polymorphism
#include <iostream>
using namespace std;


class Polygon {
  protected:
    int width, height;
  public:
    Polygon(int a, int b) : width(a), height(b){};
    virtual ~Polygon() { cout << " Polygon" << endl; }
    virtual int area (void) = 0;
    void print_area()
      	{ cout << this->area() << '\n'; }
};


class Rectangle : public Polygon {
  public:
    Rectangle(int a, int b) : Polygon(a, b){};
    ~Rectangle() { cout << "deleted Rectangle"; }
    int area()
      	{ return width * height; }
};


class Triangle : public Polygon {
  public:
    Triangle(int a, int b) : Polygon(a, b){};
    ~Triangle() { cout << "deleted Triangle"; }
    int area()
      	{ return width * height / 2; }
};


int main() {
  	Polygon* ppoly1 = new Rectangle (4, 5);
  	Polygon* ppoly2 = new Triangle (4, 5);
  	
  	ppoly1->print_area();
  	ppoly2->print_area();
  	
  	delete ppoly1;
  	delete ppoly2;
  	
  	return 0;
}
