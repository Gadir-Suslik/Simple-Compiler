#pragma once
#include <string>
#include "TokenType.hpp"
using namespace std;

struct Token{
    TokenType type;
    string value;
};