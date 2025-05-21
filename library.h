#ifndef LIBRARY
#define LIBRARY
#include <iostream>
#include "enums.h"
using namespace std;

class Library{
    string name;
    string address;
    int duration;
public:
    Library(){};

    friend ostream& operator<<(ostream& out, const Library& obj){
        out << obj.name << " " << obj.address << " " << obj.duration;
        return out;
    }

    friend istream& operator>>(istream& inp, Library& obj){
        getline(inp, obj.name);
        getline(inp, obj.address);
        string val;
        getline(inp, val);
        obj.duration = stoi(val);
        return inp;
    }
};

#endif