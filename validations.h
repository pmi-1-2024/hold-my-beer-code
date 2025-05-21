#ifndef VALIDATIONS
#define VALIDATIONS
#include <iostream>
#include <regex>
using namespace std;

bool isValidEmail(string inp){
    regex pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    return regex_match(inp,pattern);
}

bool isValidPassword(string inp){
    regex pattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[!@#$%^&*()_+\\-=\\[\\]{};':\"\\\\|,.<>\\/?]).{8,}$");
    return regex_match(inp,pattern);
}

bool isValidName(string inp){
    regex pattern("^[A-Za-z]+([-'\\s][A-Za-z]+)*$");
    return regex_match(inp,pattern);
}
#endif