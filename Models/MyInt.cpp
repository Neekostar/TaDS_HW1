//
// Created by neekostar on 01.10.22.
//
#include "MyInt.h"
#include "MyDouble.h"

istream &operator>>(istream &stream, MyINT &number) {
    number.data.clear();
    number.count = 0;
    char symbols[255];
    bool flag_sign = false;
    stream.getline(symbols, 255); // читаем поток
    for (int i = 0; symbols[i] != '\0'; i++) { // бежим по строке из потока
        if (!isdigit(symbols[i])) { // если не цифра то проверяем знак
            if ((symbols[i] == '+' || symbols[i] == '-') && !flag_sign) {
                number.sign = (symbols[i] == '-') ? true : false;
                flag_sign = true;
            } else if (!isspace(symbols[i])) { // если посторонний символ, то ошибку кидаем
                cout << "Error Input(INT)";
                throw MyException{"Input int"};
            }
        } else {
            number.data.push_back(symbols[i] - '0'); // цифру в конец вектора
            number.count++;
        }
    }
    if (number.count >= MAX_COUNT) {
        cout << "Out of range\n";
        throw MyException{"Out of range"};
    }
    stream.clear();
    return stream;
}
