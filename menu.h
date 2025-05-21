#ifndef MENU
#define MENU
#include "commander.h"
#include <iostream>
#include <functional>
#include <vector>
#include "validations.h"
using namespace std;

void sign(){}

void reg(){
  clear();
  cout << "Registration\n\n";

  User u;
  string var;

  cout << "Name: ";
  cin >>var;
  if(!isValidName(var)) throw "Wrong name";
  u.set_name(var);

  cout << "Email: ";
  cin >>var;
  if(!isValidEmail(var)) throw "Wrong email";
  u.set_email(var);

  cout << "Password: ";
  cin >>var;
  if(!isValidPassword(var)) throw "Wrong password";
  u.set_password(var);

  for(auto p: users.get_map())
      if(p.second.get_email() == u.get_email()) throw "Account with such an email already exists";
  
  users.push(u);
  throw "You have successfully registered";
}

void menu(){
  string s = "Posible commands:\n    reg\n    sign\n    exit\n\nCommand: ";
  vector<pair<string,function<void()>>> commands;
  commands.emplace_back("reg",[](){reg();});
  commands.emplace_back("sign",[](){sign();});
  commander(commands,s);
}
#endif 
