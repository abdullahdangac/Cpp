#include <iostream>
using namespace std;


struct arrWrap {
    int arr[100];
};


struct arrWrap fun()
{
    struct arrWrap x;  // structure
    cout << "address of x.arr: " << x.arr << endl;

    x.arr[0] = 10;
    x.arr[1] = 20;

    return x;
}


int main()
{
    struct arrWrap y = fun();
    
    cout << "address of y.arr: " << y.arr << endl;
    cout << "y.arr[0]: " << y.arr[0] << endl;
	cout << "y.arr[1]: " << y.arr[1] << endl;
    
    return 0;
}
