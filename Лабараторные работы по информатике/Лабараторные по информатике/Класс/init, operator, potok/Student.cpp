#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    unsigned int score;
public:
    // Задать имя студента
    void setName(string name)
    {
        this->name = name;
    }

    // Указать количество баллов за контрольную
    void setScore(unsigned int score)
    {
        this->score = score;
    }

    // Получить имя студента
    string getName() const
    {
        return this->name;
    }

    // Получить количество баллов студента
    unsigned int getScore() const
    {
        return this->score;
    }

};

std::istream& operator>>(std::istream &is, Student &s)
{
    string st;
    getline(is, st);
    s.setName(st);
    return is;
}

std::ostream& operator<<(std::ostream &is, Student& s)
{
    is << std::string("'") << s.getName() << std::string("': ") << to_string(s.getScore());

    return is;
}

int main() {

    Student s;
    cin >> s;
    s.setScore(10);
    cout << s << endl;
    return 0;
}
