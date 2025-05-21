#ifndef BOOK
#define BOOK
#include <iostream>
#include "enums.h"
using namespace std;

class Book{
    BookTypes bt;
    string name;
    int year;
    Genres gener;
    int pages;
    int author_id;
    int publisher_id;
    
public:
    Book(){};

    friend ostream& operator<<(ostream& out, const Book& obj){
        out << obj.bt << " " << obj.name << " " << obj.year << " " << obj.gener<< " " << obj.pages << " " << obj.author_id<< " " << obj.publisher_id;
        return out;
    }

    friend istream& operator>>(istream& inp, Book& obj){
        string val;
        getline(inp, val);
        obj.bt = (BookTypes)stoi(val);
        getline(inp, obj.name);
        getline(inp, val);
        obj.year = stoi(val);
        getline(inp, val);
        obj.gener = (Genres)stoi(val);
        getline(inp, val);
        obj.pages = stoi(val);
        getline(inp, val);
        obj.author_id = stoi(val);
        getline(inp, val);
        obj.publisher_id = stoi(val);

        if(obj.bt > DIGITAL || obj.bt < PAPER) throw "invalid book type argument";
        if(obj.gener > ADVENTURE || obj.gener < FANTASY) throw "invalid gener argument";
        return inp;
    }
    
};


#endif