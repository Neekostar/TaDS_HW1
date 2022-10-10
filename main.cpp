#include <iostream>
#include "CONSTANT.h"
#include "MyInt.h"
#include "MyDouble.h"
#include "MyException.h"
#include <limits>
using namespace std;

void drawing(const char first, const char second) {
    for (int i = 1; i <= 30; ++i)// MAX_COUNT; ++i )
        if (i % 10) {
            cout << first;
        } else {
            if (isspace(second)) {
                cout << i++;
            } else {
                cout << second;
            }
        }
}
void clearCIN() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
}

void enter_num(MyINT numerator, MyDOUBLE denominator) {
    numerator.data.clear();
    denominator.data.clear();
    try {
        while (true) {
            drawing(' ', ' ');
            cout << endl;
            drawing('-', '|');
            cout << endl;
            cin >> numerator;
            drawing(' ', ' ');
            cout << endl;
            drawing('-', '|');
            cout << endl;
            cin >> denominator;
            MyDOUBLE result = (numerator / denominator);
            cout << endl << "Answer:" << endl << result;
            exit(0);
        }
    }
    catch (const MyException& ex) {
        std::cout << "Error: " << ex.getError() << "\n";
        enter_num(numerator, denominator);
    }
}
int main() {
    MyINT numerator; //делимое
    MyDOUBLE denominator; //делитель
    enter_num(numerator,denominator);
    return 0;
}
