#include <iostream>
using namespace std;


int* fun()
{
    static int arr[100];  // static local variable (static storage)

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
