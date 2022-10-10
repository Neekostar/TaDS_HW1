//
// Created by neekostar on 01.10.22.
//
#include "MyInt.h"
#include "MyDouble.h"

istream &operator>>(istream &stream, MyINT &number) {
    int *item = nullptr;
    char symbol;
    bool flag_sign = false;

    stream.get(symbol);
    if (symbol == '\n')
        return stream >> number;


    while (symbol != '\n' && ((item - &number.data[0]) < MAX_COUNT)) {
        if (number.data.size()>30){
            exit(0);
        }
        if (!isdigit(symbol)) {
            if ((symbol == '+' || symbol == '-') && !item && !flag_sign) {
                number.sign = (symbol == '-') ? true : false;
                flag_sign = true;
            } else if (!isspace(symbol)) {
                cout << "Error Input(INT)";
                number.error_input = ERROR_INPUT_INT;
                while (symbol != '\n')
                    stream.get(symbol);
                return stream;
            }
        } else {
            if (item == NULL) {
                item = &number.data[0];
            }
            *item = symbol - (int) '0'; // 48
            item++;
            number.count++;
        }
        stream.get(symbol);

        if (number.data.size()>MAX_COUNT){
            cout << "Out of range\n";
            number.error_input = true;
            exit(0);
        }
    }

    if (!item && symbol == '\n')
        return stream >> number;
    return stream;
}
