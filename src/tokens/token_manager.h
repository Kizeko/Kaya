
#pragma once
#include <iostream>
#include <map>
#include "token.h"

class TokenManager {
// Private Constructor
private:
    TokenManager() = default;
// Public attributes
public:
    static std::map<std::string, EToken> readableTokens;

    template<typename T>
    static std::unique_ptr<Token<T>> getNextToken();

// Private methods
private:
template<typename T>
    static std::unique_ptr<Token<T>> makeToken(std::string identifier);
};