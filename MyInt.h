//
// Created by neekostar on 01.10.22.
//
#ifndef My_INT_H
#define My_INT_H

#include <iostream>
#include <fstream>
#include <vector>
#include "CONSTANT.h"
#include "MyException.h"

using namespace std;

class MyINT {
public:
    MyINT(const int &size) {
        data.resize(size, 0);
    }

    MyINT() {
        data.resize(MAX_COUNT, 0);
    }

    int count = 0;
    vector<int> data;
    bool sign = false;
    bool error_input = false;
};


istream &operator>>(istream &stream, MyINT &number);

#endif //TADS_HW1_MYINT_H
