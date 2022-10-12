
#include "MyException.h"
#include <iostream>
#include <fstream>
#include <chrono>
    const char *MyException::getError() const {
        return m_error.c_str();
    }
    MyException::MyException(std::string error) {
        m_error = error;
        logging();
    }

    void MyException::logging() {
        std::fstream file;
        auto now = std::chrono::system_clock::now();
        std::time_t end_time = std::chrono::system_clock::to_time_t(now);
        file.open("../log.txt", std::ios::app);
        file <<  "WARNING: " << m_error.c_str() << " | " << std::ctime(&end_time);
        file.close();
    }