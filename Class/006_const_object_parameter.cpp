#include<iostream>
using namespace std;


class myClass {
	int x;
  
public:
    myClass(int val):x(val){}
    
    int get_n()        // non-const function member
    	{ return x; } 
	int get_c()const   // const function member
		{ return x; }
};


void print_n(myClass arg) {        // non-const function parameter
	cout << arg.get_n() << endl;
}

void print_c(const myClass arg) {  // const function parameter
	cout << arg.get_c() << endl;
}


int main() {	
	myClass myc(10);
	
	print_n(myc);
	print_n(myc);
	
	return 0;
}
