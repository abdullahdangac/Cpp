#include<iostream>
using namespace std;


class myClass {
	public:
	int x, y;
	myClass() { x = 0; y = 0; }
	myClass(int a, int b) { x = a; y = b; }	
};


// class reference parameter
void func1(class myClass &obj){
	int temp = obj.x;
	obj.x = obj.y;
	obj.y = temp;
}

// pointer to class parameter & return pointer to class  
myClass *func2(class myClass *obj) {
	myClass *new_obj = new myClass();
	
	new_obj->x = obj->x;
	new_obj->y = obj->y;		
	
	return new_obj;
}

// pointer to class (class array) pointer
void func3(class myClass *obj_arr, int size) {
	for (int i=0; i<size; ++i) {
		obj_arr[i].x += 10;
		obj_arr[i].y += 10;
	}
}


int main() {	
	myClass obj1(1, 2);
	func1(obj1);
	cout << obj1.x << " " << obj1.y << endl << endl;
	
	
	myClass *objPtr;
	objPtr = func2(&obj1);
	cout << objPtr->x << " " << objPtr->y << endl << endl;
	
	
	myClass objs[2] = {{3, 4}, {5, 6}};
	func3(objs, 2);
	
	for(int i=0; i<2; i++){
		cout << objs[i].x << " " << objs[i].y << endl;
	}
	
	return 0;
}
