#pragma once
#include <sstream>
#include <string>
#include "Token.hpp"
#include "TokenType.hpp"
using namespace std;

class Lexer{
public:
    istringstream code;

    Lexer(string _code): code(_code) {}

    Token nextTok(){
        char symbol;

        code >> symbol;

        if (isdigit(symbol)){
            code.putback(symbol);
            double num;
            code >> num;
            return{
                TokenType::NUM,
                to_string(num)
            };
        }

        switch (symbol)
        {
        case '+':
            return{
                TokenType::ADD,
                "+"
            };
        case '-':
            return{
                TokenType::SUB,
                "-"
            };
        case '*':
            return{
                TokenType::MUL,
                "*"
            };
        case '/':
            return{
                TokenType::DIV,
                "/"
            };
        case ';':
            return{
                TokenType::END,
                ";"
            };
        default:
            throw runtime_error("Invalid Syntax");
        }
    }
};