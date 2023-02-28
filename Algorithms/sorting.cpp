#include<iostream>
using namespace std;


int* min2max(int *ptr, int size) {  // sorting min to max
	for (int i=0; i<size; i++) {
		for (int j=i+1; j<size; j++) {
			int temp = *(ptr+i);
			if (*(ptr+i) > *(ptr+j)) {
				*(ptr+i) = *(ptr+j);
				*(ptr+j) = temp;
			}
		}
	}
	return (ptr+0);
}


int* max2min(int *ptr, int size) {  // sorting max to min
	for (int i=0; i<size; ++i) {
		for (int j=i+1; j<size; ++j) {
			int temp = *(ptr+i);
			if (*(ptr+i) < *(ptr+j)) {
				*(ptr+i) = *(ptr+j);
				*(ptr+j) = temp;
			}
		}
	}
	return (ptr+0);
}


void print_array(const int* arr, int size) {
	for (int i=0; i<size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main() {	
	int array[5] = {-5, 73, 48, -13, 26};
	
	int *min_to_max = min2max(array, 5);
	cout << "Min to max: ";
	print_array(array, 5);
	
	int *max_to_min = max2min(array, 5);
	cout << "Max to min: ";
	print_array(array, 5);
	
	return 0;
}
