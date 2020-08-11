#include <iostream>

using namespace std;

int main()
{
    int x = 10;
    int *ptr = &x;

    cout << "x - " << x << endl; // 10
    cout << "&x - " << &x << endl; // 0x61ff0c
    cout << "ptr - " << ptr << endl; // 0x61ff0c
    cout << "*ptr - " << *ptr << endl; //10
    cout << "&ptr - " << &ptr << endl; // 0x61ff08
    cout << "*&x - " << *&x << endl; // 10
    cout << "&(*ptr) - " << &(*ptr) << endl; // 0x61ff0c
    cout << "*(&ptr) - " << *(&ptr) << endl; // 0x61ff0c

    return 0;
}