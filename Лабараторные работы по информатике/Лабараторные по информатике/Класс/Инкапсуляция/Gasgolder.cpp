#include <iostream>
#include <string>
using namespace std;

class GasHolder
{
private:
    float obyem;
    float T;
    float M;
    float m;
public:
    // Создать газгольдер заданного объёма.
    // Температура созданного термостата равна 273 К.
    GasHolder(float v)
    {
        obyem = v;
        T = 273;
        m = 0;
        M = 0;
    }

    // Уничтожить газгольдер.
    ~GasHolder()
    {

    }

    // Впрыск порции газа массой m и молярной массой M.
    // Считать, что газ принимает текущую температуру газгольдера за пренебрежимо малое время.
    void inject(float m, float M)
    {
        if(this->m!=0 && this->M!=0)
        {
        this->M = (this->m + m)/((this->m / this-> M)+(m/M));
        this->m += m;
        }
        else
        {
            this->m = m;
            this->M = M;
        }
    }

    // Подогреть газгольдер на dT градусов.
    // Считать, что нагрев возможен до любых значений температуры.
    void heat(float dT)
    {
        T += dT;
    }

    // Охладить газгольдер на dT градусов.
    // При попытке охладить ниже 0 К температура становится ровно 0 К.
    void cool(float dT)
    {
        if ((T - dT) > 0)
        {
            T -= dT;
        }
        else
        {
            T = 0;
        }
    }

    // Получить текущее давление в газгольдере.
    // Считать, что для газа верно уравнение состояния PV = (m/M)RT.
    // Значение постоянной R принять 8.31 Дж/(моль*К).
    double getPressure()
    {
        return ((m/M)*8.31*T)/obyem;
    }
};

int main(){
    GasHolder h(1.0);
    h.inject(29, 29);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.inject(29, 29);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.heat(273);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.cool(373);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.cool(373);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
}
