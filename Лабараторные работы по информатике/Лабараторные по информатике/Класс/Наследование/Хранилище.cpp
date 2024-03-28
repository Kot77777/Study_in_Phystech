#include <iostream>
#include <string>
using namespace std;

class Storage
{
private:
    int* a;
    int n;
public:
    // Конструктор хранилища размерности n
    Storage(unsigned int n)
    {
        a = new int[n];
        this->n = n;
    }

    // Добавьте нужный деструктор
    virtual ~Storage()
    {
        delete[] a;
    }

    // Получение размерности хранилища
    unsigned getSize()
    {
        return n;
    }

    // Получение значения i-го элемента из хранилища,
    // i находится в диапазоне от 0 до n-1,
    // случаи некорректных i можно не обрабатывать.
    int getValue(unsigned int i)
    {
        if(i <= n-1 && i >= 0)
        {
            return a[i];
        }
    }

    // Задание значения i-го элемента из хранилища равным value,
    // i находится в диапазоне от 0 до n-1,
    // случаи некорректных i можно не обрабатывать.
    void setValue(unsigned int i, int value)
    {
        if(i <= n-1 && i >= 0)
        {
            a[i] = value;
        }
    }
};

// Класс TestStorage, наследуется от вашей реализации Storage
class TestStorage : public Storage {
protected:
    // Унаследованная реализация зачем-то хочет выделить ещё памяти. Имеет право.
    int* more_data;

public:
    // В конструкторе память выделяется,
    TestStorage(unsigned int n) : Storage(n) {
        more_data = new int[n];
    }
    // ... а в деструкторе освобождается - всё честно.
    ~TestStorage() override {
        delete[] more_data;
    }
};

int main() {
    Storage *ts = new TestStorage(42);
    delete ts;
    return 0;
}
