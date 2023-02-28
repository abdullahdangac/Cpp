#include <iostream>
using namespace std;


int* fun()
{
    int arr[100];  // local variable (automatic storage)

    /* Some operations on arr[] */
    arr[0] = 10;
    arr[1] = 20;
    cout << "address of array : " << arr << endl;

    return arr;  // WARNING: address of local variable 'arr' returned
}


int main()
{
    int* ptr = fun();
    
    cout << "address of ptr[0]: " << (ptr+0) << endl;
    cout << "ptr[0]: " << ptr[0] << endl;
	cout << "ptr[1]: " << ptr[1] << endl;
	
    return 0;
}
