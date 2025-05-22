#ifndef MENU
#define MENU
#include "commander.h"
#include <iostream>
#include <functional>
#include <vector>
#include "validations.h"
#include "data.h"
#include "admin.h"
#include "user_.h"
#include "librarian.h"
using namespace std;

void sign(){
    clear();
    cout << "Sign In\n\n";  

    Roles role;
    int id = -1;

    string email, password;
    cout << "Email: ";
    cin >> email;
    cout<< "Password: ";
    cin >> password;
    if(!isValidEmail(email)) throw "Wrong email";
    if(!isValidPassword(password)) throw "Wrong password";
    for(auto p: users.get_map())
        if(p.second.get_email() == email){
            if(p.second.get_password() == password){
                role = (Roles)p.second.get_role();
                id = p.first;
            }
            else throw "Either the name or password is incorrect";
            break;
        }
    
    if(id == -1) throw "Such an acount does not exist";
    
    switch(role){
        case ADMIN:
            admin();
            break;
        case LIBRARIAN:
            librarian();
            break;
        case USER:
            user(id);
            break;
    }
}

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
