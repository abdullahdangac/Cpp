#include<stdio.h>


void swap1(int *a, int *b);
void swap2(int &a, int &b);


void swap1(int *a, int *b) {  // pointer parameter
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap2(int &a, int &b) {  // reference parameter
	int temp = a;
	a = b;
	b = temp;
}


int main() {		
	int x = 3, y = 4;
	printf("Before swap1: x = %d  y = %d\n", x, y);
	swap1(&x, &y);  // sending argument to pointer parameter
	printf(" After swap1: x = %d  y = %d\n", x, y);

	printf("\n");
	
	int m = 5, n = 6;
	printf("Before swap2: m = %d  n = %d\n", m, n);
	swap2(m, n);  // sending argument to reference parameter
	printf(" After swap2: m = %d  n = %d\n", m, n);

	return 0;
}
