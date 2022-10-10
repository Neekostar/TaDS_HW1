//
// Created by neekostar on 01.10.22.
//

#include "MyInt.h"
#include "MyDouble.h"

istream &operator>>(istream &stream, MyDOUBLE &number) {
    number.data.clear();
    number.count = 0;
    bool flag_sign = false;
    int point;
    char symbols[255];
    stream.getline(symbols, 255);
    for (int i = 0; symbols[i] != '\0'; i++) {
        if (!isdigit(symbols[i])) {
            if (tolower(symbols[i] != 'e')) {
                if (symbols[i] == '+' || symbols[i] == '-' && !flag_sign) {
                    if (symbols[i] == '-') {
                        number.sign = true;
                    } else number.sign = false;
                    flag_sign = true;
                } else if (symbols[i] == '.' and !point) {
                    point = number.data.size() + 1;
                } else {
                    throw MyException{"Error input (double)"};
                }
            }
        }
        else {
            number.data.push_back(symbols[i] - '0');
            number.count++;
        }
        int sum = 0;
        for (int i = 0; i < number.count; i++) {
            sum += number.data[i];
        }
        if (!sum) {
            throw MyException{"Error division by zero"};
        }
        if (tolower(symbols[i] == 'e')) {
            int zn = 1;
            for (int j = i + 1; symbols[j] != '\0'; j++) {
                number.exp = number.exp * 10 + ((int)symbols[i] - '0');
                }
        }

    }
    if ((abs(number.exp) > MAX_EXP)) {
        throw MyException{"Exp > 99999"};
    }
    reverse(&number.data[0], &number.data[number.count]);

    int j = number.count - 1;
    while (j > 0 && !number.data[j]) {
        j--;
        number.count--;
    }
    stream.clear();
    return stream;
}

ostream &operator<<(ostream &stream, const MyDOUBLE &obj) {
    MyDOUBLE obj_copy = MyDOUBLE(obj);
    stream << ((obj_copy.sign) ? "-" : "") << "0.";
    for (int i = obj_copy.count - 1; i >= 0 && i >= (obj_copy.count - 31); i--)
        stream << obj_copy.data[i];
    stream << " E " << obj_copy.exp << endl;

    return stream;
}

void MyDOUBLE::updateAsDividend() { //добавление незначащих нулей к делимому, чтобы не было косяков
    data.resize(50 + count, 0);
    for (int i = 0; i < count; i++) {
        data[i + 50] = data[i];

    }
    for (int i = 0; i < 50; i++) {
        data[i] = 0;
    }
    count += 50;
    exp -= 50;

}

void MyDOUBLE::extend() { //расширение числа на один разряд
    for (int i = count; i >= 1; i--)
        data[i] = data[i - 1];
    data[0] = 0;
    if (data[count])
        count++;
}

void MyDOUBLE::normalize() { //нормализация результата для вывода
    int i = 0;

    while (count > 0 && data[count - 1] == 0) count--;
    exp += count;
    while (data[i] == 0 && i < count)
        i++;
    for (int j = i; j < count; j++) {
        data[j - i] = data[j];
    }
    count -= i;
    if (count <= 0) count = 1;
    reverse(&data[0], &data[count]);
    if (exp < 0 && abs(exp) > MAX_EXP) {
        int sdwig = MAX_EXP - exp;
        if (sdwig <= 30) {
            for (i = 0; i < count; i++) {
                data[i + sdwig] = data[i];
            }
            for (i = 0; i < sdwig; ++i) {
                data[i] = 0;
            }
        } else {
            for (i = 0; i < MAX_COUNT; i++)
                data[i] = 0;
        }
        exp = -MAX_EXP;
        count = MAX_COUNT;
    }
    while (1) {
        if (abs(exp) >= MAX_EXP) {
            cout << "Out of range\n";
            error_input = true;
            return;
        }

        vector<int> arr_help(100, 0);
        for (i = 0; i <= MAX_COUNT + 1; i++) {
            arr_help[i] = data[i];
        }
        i = MAX_COUNT - 1;
        arr_help[i] += (arr_help[MAX_COUNT] >= 5) ? 1 : 0;
        while (i > 0 && arr_help[i] > 9) {
            arr_help[i--] %= 10;
            arr_help[i] += 1;
        }
        if (i == 0 && arr_help[i] > 9) {
            extend();
            exp += 1;
        } else {
            if (abs(exp) > MAX_EXP) {
                cout << "Out of range\n";
                error_input = ERROR_EXP;
                return;
            }
            for (i = 0; i < MAX_COUNT; i++) {
                data[i] = arr_help[i];
            }
            count = MAX_COUNT;
            break;
        }

    }
    reverse(&data[0], &data[count]);
}

void MyDOUBLE::MyINT_to_MyDOUBLE(MyINT obj) {
    count = obj.count;
    for (int i = 0; i < MAX_COUNT; ++i)
        data[i] = obj.data[i];
    exp = 0;
    error_input = obj.error_input;
    sign = obj.sign;
}

MyDOUBLE operator*(const MyDOUBLE &a, const int b) {
    MyDOUBLE res;
    res.count = a.count;
    int r = 0;
    for (int i = 0; i < res.count || r; i++) {
        res.data[i] = a.data[i] * b + r;
        r = res.data[i] / 10;
        res.data[i] -= r * 10;
    }
    while (res.data[res.count])
        res.count++;
    return res;
}

bool operator<=(const MyDOUBLE &a, const MyDOUBLE &b) {
    if (a.count != b.count)
        return a.count < b.count;
    for (int i = a.count - 1; i >= 0; i--) {
        if (a.data[i] != b.data[i])
            return a.data[i] < b.data[i];
    }
    return true;
}

MyDOUBLE operator-(const MyDOUBLE &a, const MyDOUBLE &b) {
    MyDOUBLE res = a;
    for (int i = 0; i < res.count; i++) {
        res.data[i] -= b.data[i];
        if (res.data[i] < 0) {
            res.data[i] += 10;
            res.data[i + 1]--;
        }
    }
    int pos = res.count - 1;
    while (pos && !res.data[pos])
        pos--;
    res.count = pos + 1;
    return res;
}

MyDOUBLE operator/(const MyINT &a, const MyDOUBLE &b) {
    MyDOUBLE res;
    MyDOUBLE tmp;
    MyDOUBLE a_copy;
    a_copy.MyINT_to_MyDOUBLE(a);

    reverse(&a_copy.data[0], &a_copy.data[a_copy.count]);
    a_copy.updateAsDividend();


    res.data.resize(a_copy.count, 0);

    tmp.count = 1;
    for (int i = a_copy.count - 1; i >= 0; i--) {
        tmp.extend();
        tmp.data[0] = a_copy.data[i];
        int x = 0;
        int l = 0, r = 9;

        while (l <= r) {
            int m = (l + r) >> 1;
            MyDOUBLE cur;
            cur = (b * m);
            if (cur <= tmp) {
                x = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        res.data[i] = x;
        MyDOUBLE mul;
        mul = (b * x);
        tmp = (tmp - mul);
    }

    res.count = a_copy.count;
    res.exp = a_copy.exp - b.exp;
    res.sign = (a_copy.sign + b.sign) % 2;

    res.normalize();

    return res;
}
