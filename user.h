#ifndef USER
#define USER
#include <iostream>
#include <string>


using namespace std;

class User {
private:
    int id;
    string name;
    string email;
    string password;
    int role;

public:
    User() : id(0), name(""), email(""), password(""), role(2) {}
   
    User(int id, const string& name, const string& email, const string& password, int role)
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
    void set_role(int newRole) { role = newRole; }

    void print(ostream& os) const {
        os << id << " " << name << " " << email << " " << password << " " << role;
    }
    void read(istream& is) {
        is >> this->id >> this->name >> this->email >> this->password >> this->role;
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