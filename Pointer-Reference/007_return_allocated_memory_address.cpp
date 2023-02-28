#include <iostream>
using namespace std;


int* fun()
{
    int* arr = new int[100];  // memory allocation (dynamic storage)

    /* Some operations on arr[] */
    arr[0] = 10;
    arr[1] = 20;
    cout << "address of array : " << arr << endl;
    
    return arr;
}


int main()
{
    int* ptr = fun();
    
    cout << "address of ptr[0]: " << (ptr+0) << endl;
    cout << "ptr[0]: " << ptr[0] << endl;
	cout << "ptr[1]: " << ptr[1] << endl;

    return 0;
}
