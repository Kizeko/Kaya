
#pragma once
#include <iostream>

enum class EToken : int {
    T_EOF = -1,
    T_FUN = -2,
    T_EXTERN = -3,
    T_IDENTIFIER = -4,
    T_NUMBER = -5,
    T_U8 = -6,
    T_I8 = -7,
    T_U16 = -8,
    T_I16 = -9,
    T_U32 = -10,
    T_I32 = -11,
    T_F32 = -12,
    T_U64 = -13,
    T_I64 = -14,
    T_F64 = -15,
};

template<class T>
class Token {
public:
    Token(EToken type, T value) : type_(type), value_(value) {}
    virtual ~Token() = default;

private:
    EToken type_;
    T value_;
};
