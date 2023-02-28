#include<iostream>
using namespace std;


template <typename T> class Array {
private:
	T *ptr;
	int size;
  
public:
    Array(T arr[], int s);  // constructor
    void print();
};

template <typename T> Array<T>::Array(T arr[], int s) {
	ptr = new T[s];
	size = s;
	for (int i = 0; i < size; i++) {
		ptr[i]=arr[i];
	}
}

template <typename T> void Array<T>::print() {
	for (int i = 0; i < size; i++)
	   cout << " " << *(ptr + i);
   
   cout<<endl;
}


int main() {
	int iarr[5] = {1, 2, 3, 4, 5};
	double darr[3] = {2.3, 4.7, 8.5};
	
	Array <int> i_arr(iarr, 5);
	i_arr.print();
	
	Array <double> d_arr(darr, 3);
	d_arr.print();	
	
	return 0;
}
