#include <iostream>
#include <math.h>

using namespace std;

double area(double radius)
{
    return (M_PI * radius * radius);
}

double area(double l, double b)
{
    return (l * b);
}

int main()
{
    cout << "Area of circle : " << area(2) << endl;
    cout << "Area of rectangle : " << area(10, 20) << endl;

    return 0;
}