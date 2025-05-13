#ifndef STRUCTURES
#define STRUCTURES

#include <iostream>
using namespace std;

enum Roles{
    ADMIN,
    LIBRARIAN,
    USER
};

enum BookTypes{
    PAPER,
    DIGITAL
};

enum Genres{
    FANTASY,
    HORROR,
    MYSTERY,
    THRILLER,
    DRAMA,
    HISTORY,
    FICTION,
    ADVENTURE
};

struct Author{
    string first_name;
    string last_name;

    Author(){};

    friend ostream& operator<<(ostream& out, const Author& obj){
        out << obj.first_name << "," << obj.last_name;
        return out;
    }

    friend istream& operator>>(istream& inp, Author& obj){
        getline(inp, obj.first_name,',');
        getline(inp, obj.last_name,',');
        return inp;
    }
};

struct Publisher{
    string name;
    string email;

    Publisher(){};

    friend ostream& operator<<(ostream& out, const Publisher& obj){
        out << obj.name << "," << obj.email;
        return out;
    }

    friend istream& operator>>(istream& inp, Publisher& obj){
        getline(inp, obj.name,',');
        getline(inp, obj.email,',');
        return inp;
    }
};

struct Book{
    BookTypes bt;
    string name;
    int year;
    Genres gener;
    int pages;
    int author_id;
    int publisher_id;

    Book(){};

    friend ostream& operator<<(ostream& out, const Book& obj){
        out << obj.bt << "," << obj.name << "," << obj.year << "," << obj.gener<< "," << obj.pages << "," << obj.author_id<< "," << obj.publisher_id;
        return out;
    }

    friend istream& operator>>(istream& inp, Book& obj){
        string val;
        getline(inp, val,',');
        obj.bt = (BookTypes)stoi(val);
        getline(inp, obj.name,',');
        getline(inp, val,',');
        obj.year = stoi(val);
        getline(inp, val,',');
        obj.gener = (Genres)stoi(val);
        getline(inp, val,',');
        obj.pages = stoi(val);
        getline(inp, val,',');
        obj.author_id = stoi(val);
        getline(inp, val,',');
        obj.publisher_id = stoi(val);
        return inp;
    }
    
};

struct Library{
    string name;
    string address;
    int duration;

    Library(){};

    friend ostream& operator<<(ostream& out, const Library& obj){
        out << obj.name << "," << obj.address << "," << obj.duration;
        return out;
    }

    friend istream& operator>>(istream& inp, Library& obj){
        getline(inp, obj.name,',');
        getline(inp, obj.address,',');
        string val;
        getline(inp, val,',');
        obj.duration = stoi(val);
        return inp;
    }
};

struct User{
    string name;
    string email;
    string password;
    Roles role;

    User(){};
    User(string n, string e, string p, Roles r):name(n),email(e),password(p),role(r){};
    friend ostream& operator<<(ostream& out, const User& obj){
        out << obj.name << "," << obj.email << "," << obj.password << "," << obj.role;
        return out;
    }

    friend istream& operator>>(istream& inp, User& obj){
        getline(inp, obj.name,',');
        getline(inp, obj.email,',');
        getline(inp, obj.password,',');
        string val;
        getline(inp, val,',');
        obj.role = (Roles)stoi(val);
        return inp;
    }
};

struct LibraryBook{
    int amount_of_books;
    int library_id;
    int book_id;

    LibraryBook(){};

    friend ostream& operator<<(ostream& out, const LibraryBook& obj){
        out << obj.amount_of_books << "," << obj.library_id << "," << obj.book_id;
        return out;
    }

    friend istream& operator>>(istream& inp, LibraryBook& obj){
        string val;
        getline(inp, val,',');
        obj.amount_of_books = stoi(val);
        getline(inp, val,',');
        obj.library_id = stoi(val);
        getline(inp, val,',');
        obj.book_id = stoi(val);
        return inp;
    }
};

struct Order{
    int user_id;
    int lbook_id;
    string date;

    Order(){};

    friend ostream& operator<<(ostream& out, const Order& obj){
        out << obj.user_id << "," << obj.lbook_id << "," << obj.date;
        return out;
    }

    friend istream& operator>>(istream& inp, Order& obj){
        string val;
        getline(inp, val,',');
        obj.user_id = stoi(val);
        getline(inp, val,',');
        obj.lbook_id = stoi(val);
        getline(inp, obj.date,',');
        return inp;
    }
};

#endif