

#ifndef LAB1_MYEXCEPTION_H
#define LAB1_MYEXCEPTION_H
#include <string>
#include <string_view>
    class MyException {
    private:
        void logging();
        std::string m_error;
    public:
        MyException(std::string error);
        const char* getError() const;
    };

#endif //LAB1_MYEXCEPTION_H
