#include <iostream>
#include "CONSTANT.h"
#include "MyInt.h"
#include "MyDouble.h"

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

int main() {
    MyINT numerator; //делимое
    MyDOUBLE denominator; //делитель

    drawing(' ', ' ');
    cout << endl;
    drawing('-', '|');
    cout << endl;
    cin >> numerator;
    if (!numerator.error_input) {
        drawing(' ', ' ');
        cout << endl;
        drawing('-', '|');
        cout << endl;
        cin >> denominator;
        if (!denominator.error_input) {
            MyDOUBLE result = (numerator / denominator);
            if (!result.error_input)
                cout << endl << "Answer:" << endl << result;
        }
    } else{
        exit(0);
    }

    return 0;
}
