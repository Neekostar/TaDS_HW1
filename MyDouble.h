//
// Created by neekostar on 01.10.22.
//
#ifndef My_DOUBLE_H
#define My_DOUBLE_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include "CONSTANT.h"
#include "MyInt.h"

using namespace std;


class MyDOUBLE {
public:
    MyDOUBLE(const int &size) {
        data.resize(size, 0);
    }

    MyDOUBLE() {
        data.resize(MAX_COUNT, 0);
    }

    int count = 0;
    vector<int> data;
    int exp = 0;
    bool sign = false;
    bool error_input = false;

    void updateAsDividend();

    void extend();

    void normalize();

    void MyINT_to_MyDOUBLE(MyINT obj);

};

istream &operator>>(istream &stream, MyDOUBLE &number);

ostream &operator<<(ostream &stream, const MyDOUBLE &obj);

MyDOUBLE operator/(const MyINT &a, const MyDOUBLE &b);

MyDOUBLE operator*(const MyDOUBLE &a, const int b);

bool operator<=(const MyDOUBLE &a, const MyDOUBLE &b);

MyDOUBLE operator-(const MyDOUBLE &a, const MyDOUBLE &b);

#endif //TADS_HW1_MYDOUBLE_H
