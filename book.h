#ifndef BOOK
#define BOOK
#include <iostream>
#include "enums.h"
using namespace std;

class Book{
    int id;
    BookTypes book_type;
    string name;
    int year;
    Genres gener;
    int pages;
    int author_id;
    int publisher_id;
    
public:
    Book(){};

    int get_id(){return id;}
    string get_name(){return name;}
    int get_book_type(){return book_type;}
    int get_year(){return year;}
    int get_gener(){return gener;}
    int get_pages(){return pages;}
    int get_author_id(){return author_id;}
    int get_publisher_id(){return publisher_id;}

    void set_id(int a){id = a;}
    void set_name(string n){ name = n;}
    void set_book_type(int a){ book_type= (BookTypes)a;}
    void set_year(int a){ year= a;}
    void set_gener(int a){ gener = (Genres)a;}
    void set_pages(int a){ pages= a;}
    void set_author_id(int a){ author_id= a;}
    void set_publisher_id(int a){ publisher_id= a;}

    friend ostream& operator<<(ostream& out, const Book& obj){
        out << obj.id << " " << obj.book_type << " " << obj.name << " " << obj.year << " " << obj.gener<< " " << obj.pages << " " << obj.author_id<< " " << obj.publisher_id;
        return out;
    }

    friend istream& operator>>(istream& inp, Book& obj){
        inp >> obj.id;
        string val;
        inp >> val;
        obj.book_type = (BookTypes)stoi(val);
        inp >> obj.name;
        inp >> obj.year;
        inp >> val;
        obj.gener = (Genres)stoi(val);
        inp >> obj.pages;
        inp >> obj.author_id;
        inp >> obj.publisher_id;

        if(obj.book_type > DIGITAL || obj.book_type < PAPER) throw "invalid book type argument";
        if(obj.gener > ADVENTURE || obj.gener < FANTASY) throw "invalid gener argument";
        return inp;
    }
    
};


#endif
