#ifndef MENU
#define MENU
#include "commander.h"
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

void sign(){}

void reg(){}

void menu(){
  string s = "Posible commands:\n    reg\n    sign\n    exit\n\nCommand: ";
  vector<pair<string,function<void()>>> commands;
  commands.emplace_back("reg",[](){reg();});
  commands.emplace_back("sign",[](){sign();});
  commander(commands,s);
}
#endif 
