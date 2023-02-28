#include<iostream>
using namespace std;


int &get_array(int size){
	int *arr = new int[size];
	
	for (int i = 0; i < size; ++i) {
		arr[i] = i + 1;
	}
	
	return *arr;
}


void print_array(const int* arr, int size) {
	for (int i = 0; i < size; ++i) { 
		cout << arr[i] << " ";
	} 
	cout << endl;
}


int main() {	
	int &array = get_array(10);
	print_array(&array, 10);
	
	array = 99;
	print_array(&array, 10);	
	
	return 0;
}
