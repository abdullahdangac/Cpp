#include<iostream>
using namespace std;


class myClass{
public:
	int x;
	myClass(int val):x(val){};  // constructor
	void get_n()                // non-const function member
		{ cout << x << endl; }
	void get_c()const           // const function member
		{ cout << x << endl; }
};


int main(){	
	const myClass myc(10);      // const object

	//myc.x = 20;  //ERROR
	cout << myc.x << endl;      // read-only access to member
	
	//myc.get_n();  //ERROR
	myc.get_c();                // access to const function member
	
	return 0;
}
