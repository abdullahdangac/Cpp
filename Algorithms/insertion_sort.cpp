#include<iostream>
#include<iomanip>
using namespace std;
using std::setw;


template<typename T>
void insertionSort(T* array, int size) {
	T insert;
	
	for (int idx=0; idx<size; ++idx) {
		insert = array[idx];
		int moveItem = idx;
	  
		while (moveItem>0 && array[moveItem - 1]>insert) {
  	  		array[moveItem] = array[moveItem - 1];
  	  		--moveItem;	
  		}
     	array[moveItem] = insert;
	}
}


template<typename T>
void printArray(T const* array, int size) {
	for(int i=0; i<size; i++){
		cout << setw(6) << array[i];
	}
	cout << endl;
}


int main() {
	const int size = 10;
	int a[size] = {6, 3, 8, 2, 10, 5, 4, 9, 7, 1};
	
	cout << "original array" << endl;
	printArray(a, size);
	
	insertionSort(a, size);
	
	cout << "sorted array" << endl;
	printArray(a, size);

	return 0;
}
