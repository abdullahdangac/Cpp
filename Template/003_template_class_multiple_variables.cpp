#include<iostream>
using namespace std;


template <class T, class U> class myPair {
	T a;
	U b;
 
public:
	myPair(T, U);
	void print_max();
};

template <class T, class U> myPair<T, U>::myPair(T first, U second) {
	a = first;
	b = second;
}

template <class T, class U> void myPair<T, U>::print_max() {
	cout << ((a > b) ? a : b) << endl;
}


int main() {
	myPair <int, int> pair1(100, 75);
    myPair <int, double> pair2(19, 76.4);
	
	pair1.print_max();
	pair2.print_max();
	
	return 0;
}
