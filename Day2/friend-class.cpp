#include <iostream>

using namespace std;

class Friend
{
    private:
    string name;
    int age;

    public:
    Friend(string name = "default", int age = 18)
    {
        cout << "Constructor called..." << endl;
        this->name = name;
        this->age = age;
    }

    ~Friend()
    {
        cout << "Destructor called..." << endl;
    }

    string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setAge(int age)
    {
        this->age = age;
    }
};

int main()
{
    Friend f1("Razi");

    cout << f1.getAge() << " " << f1.getName() << endl;

    return 0;
}