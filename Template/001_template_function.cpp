#include<iostream>
using namespace std;


template <typename T> T getMax(T a, T b) {
	return (a > b) ? a : b;
}


template <typename T, typename U> T getMin(T a, U b) {
	return (a < b) ? a : b;
}


int main() {
	int i = 5, j = 7;
	long l = 10, m = 3;
   
	cout << getMax <int> (i, j) << endl;
	cout << getMax <long> (l, m) << endl;
   
   
	int x = 24;
	double y = 95.7;
	cout << getMin <int, double> (x, y) << endl;
      
	return 0;
}
