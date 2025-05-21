
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
    User() : id(0), name(""), email(""), password(""), role(0) {}
   
    User(int id, const string& name, const string& email, const string& password, int role)
        : id(id), name(name), email(email), password(password), role(role) {}

    
    int get_id() const { return id; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getPassword() const { return password; }
    int getRole() const { return role; }

   
    void setId(int newId) { id = newId; }
    void setName(const string& newName) { name = newName; }
    void setEmail(const string& newEmail) { email = newEmail; }
    void setPassword(const string& newPassword) { password = newPassword; }
    void setRole(int newRole) { role = newRole; }

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

