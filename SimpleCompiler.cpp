#include <iostream>
#include <cctype>
#include "Parser.hpp"

using namespace std;

int main(){
    string code = "2 + 2 * 0 * 8;";
    auto parser = Parser(code);
    try{
        auto result = parser.parseExpression();
        cout << "successfully compiled: " << result << endl;
    }
    catch (exception& ex) {
        cerr << "Error was found while compilating this code: " << ex.what();
    }
}