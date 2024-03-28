#include <iostream>
#include <string>
using namespace std;

class Material
{
public:
    // Принимает на вход величину деформации.
    // Возвращает величину напряжения, посчитанную с учётом реологии материала.
    virtual float getStress(float strain) = 0;
};

class ElasticMaterial: public Material
{
private:
    float elasticModulus;
public:
    ElasticMaterial(float elasticModulus)
    {
        this->elasticModulus = elasticModulus;
    }

    float getStress(float strain) override
    {
        return (this->elasticModulus)*strain;
    }
};

class PlasticMaterial: public Material
{
private:
    float elasticModulus;
    float strainLimit;
public:
    PlasticMaterial(float elasticModulus, float strainLimit)
    {
        this->elasticModulus = elasticModulus;
        this->strainLimit = strainLimit;
    }

    float getStress(float strain) override
    {
        if(strain <= this->strainLimit)
        {
            return (this->elasticModulus)*strain;
        }
        else
        {
            return (this->elasticModulus)*(this->strainLimit);
        }
    }
};

int main()
{

    Material* m;
    m = new ElasticMaterial(100);
    cout << "Material stress is: " << m->getStress(0.1) << endl;
    delete m;
    m = new PlasticMaterial(100, 0.01);
    cout << "Material stress is: " << m->getStress(0.1) << endl;
    delete m;
    return 0;
}
