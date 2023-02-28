#include <iostream>
using namespace std;


class Rectangle {
	int width, height;
  public:
	Rectangle(int, int);
	//Rectangle(int a, int b) : width(a), height(b){};
	//Rectangle(int a, int b) { width = a; height = b; } 
	int area()
		{ return width * height; }
};

Rectangle::Rectangle(int a, int b) {
	width = a;
    height = b;
}


int main() {  
	Rectangle recta(3, 4);
    Rectangle rectb(5, 8);

    cout << "recta area: " << recta.area() << endl;
    cout << "rectb area: " << rectb.area() << endl;
  
	return 0;
}
