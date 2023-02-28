#include <iostream>
using namespace std;


class Rectangle {
	int width, height;
  public:
	Rectangle();
	Rectangle(int, int);
	int area() 
		{ return width * height; }   
};

Rectangle::Rectangle() {
	width = 5;
	height = 8;
}

Rectangle::Rectangle(int a, int b) {
	width = a;
	height = b;
}


int main() {
	Rectangle recta;
	Rectangle rectb(3, 4);

	cout << "recta area: " << recta.area() << endl;
	cout << "rectb area: " << rectb.area() << endl;

	return 0;
}
