#include<iostream>
using namespace std;


class myClass {
  public:
	int x, y;
	myClass *nextptr;
	myClass() { x = 0; y = 0; nextptr = NULL; }
	myClass(int a, int b, myClass *nxt) { x = a; y = b; nextptr = nxt; }
};


typedef class myClass myClass;
typedef myClass *myClassPtr;


int main() {
	// pointer class member
	myClass obj1(1, 2, NULL);
	myClass obj2(10, 20, NULL);	
	obj1.nextptr = &obj2;
		
	cout << obj1.x << endl;
	cout << obj1.nextptr->x << endl;
	
	
	// pointer to class	
	myClassPtr objPtr;
	objPtr = &obj1;
	
	cout << objPtr->y << endl;
	cout << objPtr->nextptr->y << endl;

	
	// class array
	myClass objs[2] = {{100, 200, NULL}, {1000, 2000, NULL}};
	objs[0].nextptr = &objs[1];
	
	cout << objs[0].x << endl;
	cout << objs[0].nextptr->x << endl;
	
	
	// dynamic memory management for class
	myClassPtr new_objs = new myClass[2];
	new_objs[0] = objs[0];
	new_objs[1] = objs[1];
	
	cout << new_objs[0].y << endl;
	cout << new_objs[0].nextptr->y << endl;
	
	return 0;
}
