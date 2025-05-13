#ifndef CMD
#define CMD
#include <iostream>
#include "data.h"
#include "validations.h"
using namespace std;
void menu(string msg = "");
void clear(){
    int a = system("cls");
        if(a != 0) system("clear"); // this command for linux for Window you should use system("cls");
}

void admin(int session_id){
    return;
};

void librarian(int session_id){
    return;
};

void user(int session_id){
    return;
};

void sign(){
    string name,email,password;
    clear();
    cout << "Sign In\n\n";
    cout << "Name: ";
    cin >> name;
    cout << "Email: ";
    cin >> email;
    cout << "Password: ";
    cin >> password;
    
    if(!isValidName(name)){menu("Wrong name"); return;}
    if(!isValidEmail(email)){menu("Wrong email"); return;}
    if(!isValidPassword(password)){menu("Wrong password"); return;}

    //code of finding and entering
    Roles role;
    int id = -1;

    for(auto p: users.give_map())
        if(p.second.email == email){
            if(p.second.name == name & p.second.password == password){
                role = p.second.role;
                id = p.first;
            }
            else{menu("Either the name or password is incorrect");return;}
            break;
        }
    
    if(id == -1){menu("Such an acount does not exist"); return;}
    
    switch(role){
        case ADMIN:
            admin(id);
            return;
        case LIBRARIAN:
            librarian(id);
            return;
        case USER:
            user(id);
            return;
    }
}

void reg(){
    string name,email,password;
    clear();
    cout << "Registration\n\n";
    cout << "Name: ";
    cin >> name;
    cout << "Email: ";
    cin >> email;
    cout << "(At least 8 characters, upperscale letter, lowerscale letter, one digit and one special character)\nPassword: ";
    cin >> password;

    if(!isValidName(name)){menu("Wrong name"); return;}
    if(!isValidEmail(email)){menu("Wrong email"); return;}
    if(!isValidPassword(password)){menu("Wrong password"); return;}

    for(auto p: users.give_map())
        if(p.second.email == email){menu("Account with such an email already exists"); return;}
    
    User u(name,email,password,USER);
    users.push(u);
    menu("You have successfully registered");
}

void menu(string msg){
    clear();
    cout << msg <<"\n\n";
    cout << "Posible commands:\n    register -> R\n    sign in  -> S\n    exit     -> E\n\nCommand: ";
    string request;
    cin >> request;
    if(request == "R"){
        reg();
        return;
    }
    if(request == "S"){
        sign();
        return;
    }
    if(request == "E"){
        return;
    }
    clear();
    menu("Wrong command");
}

#endif