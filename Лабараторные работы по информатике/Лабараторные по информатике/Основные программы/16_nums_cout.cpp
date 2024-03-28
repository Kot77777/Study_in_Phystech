#include <iostream>
using namespace std;
int hexToDecimal(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    }
    else if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    }
    else {
        return -1; // некорректный символ
    }
}

int readHexNumber() {
    int number = 0;
    char hex;
    while (cin.get(hex) && hex != ' ' && hex != '\n') {
        int digit = hexToDecimal(hex);
        if (digit == -1) {
            return 0; // некорректный символ
        }
        number = number * 16 + digit;
    }
    return number;
}

int main() {
    int decimal = readHexNumber();
    cout << decimal << endl;
    return 0;
}
