#include <iostream>
using namespace std;
int decimalToBinary(int decimal) {
    int binary = 0, base = 1;
    while (decimal > 0) {
        binary += (decimal % 2) * base;
        decimal /= 2;
        base *= 10;
    }
    return binary;
}

int decimalToTernary(int decimal) {
    int ternary = 0, base = 1;
    while (decimal > 0) {
        ternary += (decimal % 3) * base;
        decimal /= 3;
        base *= 10;
    }
    return ternary;
}

int main() {
    int decimal;
    cin >> decimal;
    int binary = decimalToBinary(decimal);
    cout << binary << endl;

    int decimal1;
    cin >> decimal1;
    int ternary = decimalToTernary(decimal1);
    cout << ternary << endl; // выводит 1000
    return 0;
}
