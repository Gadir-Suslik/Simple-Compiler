
#include "Token.hpp"
#include "TokenType.hpp"
#include "Lexer.hpp"
using namespace std;

class Parser{
public:
    Lexer lex;
    Token current;

    Parser(string code) : lex(code){}

    void peek(){
        current = lex.nextTok();
    }

    int additive(){
        int leftNode = multiplicatable();

        while (current.type == TokenType::ADD || current.type == TokenType::DIV){
            Token oper = current;
            peek();
            int rightNode = multiplicatable();
            if (oper.type == TokenType::ADD){
                leftNode += rightNode;
            }
            else if (oper.type == TokenType::SUB){
                leftNode -= rightNode;
            }
        }

        return leftNode;
    }

    int multiplicatable() {
        int leftNode = parseValue();

        while (current.type == TokenType::MUL || current.type == TokenType::DIV){
            Token oper = current;
            peek();
            int rightNode = parseValue();

            if (oper.type == TokenType::MUL){
                leftNode *= rightNode;
            }
        }

        return leftNode;
    }

    int parseValue(){
        int val = stoi(current.value);
        peek();
        return val;
    }

    int parseExpression(){
        peek();
        return additive();
    }
};