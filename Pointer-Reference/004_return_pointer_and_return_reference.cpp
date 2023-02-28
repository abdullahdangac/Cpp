#include<iostream>
using namespace std;


int* get_min(int *ptr, int size) {  // return pointer
	int idx = 0;
	for (int i=0; i<size; ++i) {
		if (ptr[idx] > ptr[i]){
			idx = i;
		}
	}
	return (ptr+idx);
}


int& get_max(int *ptr, int size) {  // return reference
	int idx = 0;
	for (int i=0; i<size; ++i) {
		if (ptr[idx] < ptr[i]){
			idx = i;
		}
	}
	return *(ptr+idx);
}


void print_array(const int* arr, int size) {
	for (int i=0; i<size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main() {	
	int array[5] = {-5, 73, 48, -13, 26};
	print_array(array, 5);
	cout << "----------------------------------" << endl;	
	
	
	// getting value from pointer return
	int *min_ptr = get_min(array, 5);  
	cout << "Min value of array: " << *min_ptr << endl;
	
	// assigning value to variable by pointer
	*min_ptr = -100;
	cout << "Min value of array changed to -100" << endl;
	cout << "Min value of array: " << *min_ptr << endl;
	print_array(array, 5);
	cout << "----------------------------------" << endl;	
	
	
	// getting value from reference return
	int &max = get_max(array, 5);  
	cout << "Max value of array: " << max << endl;
	
	// assigning value to variable by reference
	max = 100;
	cout << "Max value of array changed to 100" << endl;
	cout << "Max value of array: " << max << endl;
	
	print_array(array, 5);
	cout << "----------------------------------" << endl;
	
		
	return 0;
}
