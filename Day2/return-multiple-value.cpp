#include <iostream>

using namespace std;

class CalculatedValues
{
    public:
    double add;
    double sub;
    double multiply;
    double divide;

    CalculatedValues(double a, double b)
    {
        add = a + b;
        sub = a - b;
        multiply = a * b;
        divide = a / b;
    }
};

CalculatedValues* calculator(double a, double b)
{
    CalculatedValues* result = new CalculatedValues(a, b);
    return result;
}

int main()
{
    CalculatedValues* c1 = calculator(10, 20);

    cout << &c1 << endl;
    
    cout << c1->add << " " << c1->sub << " " << c1->multiply << " " << c1->divide << endl;

    return 0;
} 