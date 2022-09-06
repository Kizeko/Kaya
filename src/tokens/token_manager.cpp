#include "token_manager.h"

std::map<std::string, EToken> TokenManager::readableTokens = {
                                                            {"fun", EToken::T_FUN},
                                                            {"extern", EToken::T_EXTERN},
                                                            {"u8", EToken::T_U8},
                                                            {"i8", EToken::T_I8},
                                                            {"u16", EToken::T_U16},
                                                            {"i16", EToken::T_I16},
                                                            {"u32", EToken::T_U32},
                                                            {"i32", EToken::T_I32},
                                                            {"f32", EToken::T_F32},
                                                            {"u64", EToken::T_U64},
                                                            {"i64", EToken::T_I64},
                                                            {"f64", EToken::T_F64},
                                                            };

template<typename T>
std::unique_ptr<Token<T>> TokenManager::makeToken(std::string identifier) {
    auto pos = TokenManager::readableTokens.find(identifier);
    if(pos != TokenManager::readableTokens.end()) {
        // Identifier is a readable token, we're returning it.
        return std::make_unique<Token<T>>(pos->second, identifier);
    } else {
        // TODO PROBLEM IDENTIFIER NOT FOUND
    }
}

template<typename T>
std::unique_ptr<Token<T>> TokenManager::getNextToken() {
    // Defining the lastCharacter variable as a space
    int lastCharacter = ' ';

    // Skipping every space until we find a non-space character
    while(isspace(lastCharacter)) {
        lastCharacter = getchar();
    }

    // Character found, we start by checking if the first character is alpha
    if(isalpha(lastCharacter)) {
        // First character is alpha, we instantiate the identifier variable
        std::string identifier;

        // While character is alphanumeric we push it in the variable
        while(isalnum(lastCharacter)) {
            identifier.push_back(lastCharacter);
            lastCharacter = getchar();
        }
        return makeToken<std::string>(identifier);

    } else if(isdigit(lastCharacter)) {
        // Character is a digit, this is therefore a number value
        std::string number;

        // While it's a digit or a dot, we continue to store in the variable
        while(isdigit(lastCharacter) || lastCharacter == '.') {
            number.push_back(lastCharacter);
            lastCharacter = getchar();
        }

        // Return the number
        return std::make_unique<Token<T>>();

    }
}