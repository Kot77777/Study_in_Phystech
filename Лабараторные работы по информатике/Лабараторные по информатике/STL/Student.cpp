#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
private:
    string name;
public:
    Student(string name)
    {
        this->name = name;
        cout << "I was born" << endl;
    }

    ~Student()
    {
        cout << "I was expelled" << endl;
    }
};

int main()
{
    vector<Student> v;
    v.reserve(10);
    Student a("Vasy");
    v.push_back(a);
    v.push_back(a);
    v.push_back(a);

    return 0;
}
