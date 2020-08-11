#include <iostream>

using namespace std;

int main()
{
    int num = 10;
    char ch = 'a';

    int* ptr1 = &num;
    char* ptr2 = &ch;

    cout << "num = " << num << endl; // 10
    cout << "ptr1 = " << ptr1 << endl; // 0x123...
    cout << "ch = " << ch << endl;  // 'a'
    cout << "ptr2 = " << ptr2 << endl; // 'a'
    cout << "(void *)ptr2 = " << (void *)ptr2 << endl; // 0x2145...

    void *ptr = &num;
    cout << ptr << endl;
    ptr = &ch;
    cout << ptr << endl;

    return 0; 
}