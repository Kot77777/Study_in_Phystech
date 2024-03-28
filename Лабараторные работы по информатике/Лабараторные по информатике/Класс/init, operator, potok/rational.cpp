#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  if (b % a == 0)
    return a;
  if (a > b)
    return gcd(a%b, b);
  return gcd(a, b%a);
}

class Rational
{
private:
    bool a = true;
    int numerator;
    int denumerator;
public:
    void setbool(bool g)
    {
        this->a= g;
    }

    void setNumerator(int a)
    {
        this->numerator = a;
    }

    void setDenumerator(int a)
    {
        this->denumerator = a;
    }

    bool detbool() const
    {
        return this->a;
    }

    int getNumerator() const
    {
        return this->numerator;
    }

    int getDenumerator() const
    {
        return this->denumerator;
    }

    void shorten_the_fraction()
    {
        int f = gcd(abs(this->numerator), abs(this->denumerator));
        this->numerator /= f;
        this->denumerator /= f;
        if (this->denumerator < 0)
        {
            this->denumerator *= -1;
            this->numerator *= -1;
        }
    }

    bool check_user(const int& a) const
    {
        if (a==0)
        {
            cout << "На 0 делить нельзя, введите дробь заново" << endl;
            return false;
        }
        return true;
    }

    Rational operator+(const Rational& r) const
    {
        Rational c;
        c.setNumerator(this->getNumerator()*r.getDenumerator() + this->getDenumerator()*r.getNumerator());
        c.setDenumerator(this->getDenumerator()*r.getDenumerator());
        return c;
    }

    Rational operator-(const Rational& r) const
    {
        Rational c;
        c.setNumerator(this->getNumerator()*r.getDenumerator() - this->getDenumerator()*r.getNumerator());
        c.setDenumerator(this->getDenumerator()*r.getDenumerator());
        return c;
    }

    Rational operator*(const Rational& r) const
    {
        Rational c;
        c.setNumerator(this->getNumerator()*r.getNumerator());
        c.setDenumerator(this->getDenumerator()*r.getDenumerator());
        return c;
    }

    Rational operator/(const Rational& r) const
    {
        Rational c;
        if(r.getNumerator() != 0)
        {
            c.setNumerator(this->getNumerator()*r.getDenumerator());
            c.setDenumerator(this->getDenumerator()*r.getNumerator());
        }
        else
        {
            c.setbool(false);
        }
        return c;
    }

    friend std::ostream& operator<<(std::ostream& os, const Rational &r);
    friend std::istream& operator>>(std::istream &is, Rational &r);
};

std::ostream& operator<<(std::ostream& os, const Rational &r)
{
    r.shorten_the_fraction();
    if (r.getNumerator() == 0){
        os << 0;}
    else{ if (r.getDenumerator() == 1){
            os << r.getNumerator();}
        else{
            os << r.getNumerator() << "/" << r.getDenumerator();}}
    return os;
}

std::istream& operator>>(std::istream &is, Rational &r)
{
    cout << "Введите дробь:" << endl;
    string inputString;
    is >> inputString;

    size_t pos = inputString.find('/'); // находим позицию разделителя

    std::string resultString1 = inputString.substr(0, pos); // вырезаем часть строки до разделителя
    std::string resultString2 = inputString.substr(pos + 1); // вырезаем часть строки после разделителя

    r.numerator = stoi(resultString1);
    r.denumerator = stoi(resultString2);

    return is;
}


int main() {
    setlocale(LC_ALL, "Russian");
    Rational a;
    do
    {
        cin >> a;
    }while(!a.check_user(a.getDenumerator()));
    cout << a << endl;

    Rational b;
    do
    {
        cin >> b;
    }while(!b.check_user(b.getDenumerator()));
    cout << b << endl;

    Rational c = a + b;
    cout << "Сумма = " << c << endl;

    Rational d = a - b;
    cout << "Разность = " << d << endl;

    Rational e = a * b;
    cout << "Произведение = " << e << endl;

    Rational f = a / b;
    if(f.detbool())
    {
        cout << "Отношение = " << f << endl;
    }
    else
    {
        cout << "не определено, учи математику" << endl;
    }
    return 0;
}
