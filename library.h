#ifndef LIBRARY
#define LIBRARY
#include <iostream>
#include "enums.h"
using namespace std;

class Library{
    int id;
    string name;
    string address;
    int duration;
public:
    Library(){};

    int get_id(){return id;}
    string get_name(){return name;}
    string get_address(){return address;}
    int get_duration(){return duration;}

    void set_name(string n){name = n;}
    void set_address(string a){address = address;}
    void set_duration(int d){duration = d;}
    void set_id(int i){id = i;}

    friend ostream& operator<<(ostream& out, const Library& obj){
        out <<obj.id << " " << obj.name << " " << obj.address << " " << obj.duration;
        return out;
    }

    friend istream& operator>>(istream& inp, Library& obj){
        string val;
        inp >> obj.id >> obj.name >> obj.address >> val;
        obj.duration = stoi(val);
        return inp;
    }
};

#endif
