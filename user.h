#ifndef USERRRR
#define USERRRR
#include <iostream>
#include <string>
#include "enums.h"


using namespace std;

class User {
private:
    int id;
    string name;
    string email;
    string password;
    Roles role;

public:
    User() : id(0), name(""), email(""), password(""), role(USER) {}
   
    User(int id, const string& name, const string& email, const string& password, Roles role)
        : id(id), name(name), email(email), password(password), role(role) {}

    
    int get_id() const { return id; }
    string get_name() const { return name; }
    string get_email() const { return email; }
    string get_password() const { return password; }
    int get_role() const { return role; }

   
    void set_id(int newId) { id = newId; }
    void set_name(const string& newName) { name = newName; }
    void set_email(const string& newEmail) { email = newEmail; }
    void set_password(const string& newPassword) { password = newPassword; }
    void set_role(Roles newRole) { role = newRole; }

    void print(ostream& os) const {
        os << id << " " << name << " " << email << " " << password << " " << role;
    }
    void read(istream& is) {
        string val;
        is >> this->id >> this->name >> this->email >> this->password >> val;
        role = (Roles)stoi(val);
    }

    friend ostream& operator<<(ostream& os, const User& user) {
        user.print(os);
        return os;
    }

    friend istream& operator>>(istream& is, User& user) {
        user.read(is);
        return is;
    }
};

#endif