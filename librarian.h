#ifndef ADMIN_
#define ADMIN_
#include "commander.h"
#include <iostream>
#include <functional>
#include <vector>
#include "validations.h"
#include "data.h"
#include "enums.h"
using namespace std;


string input_str(int n, string fields[]){
    string s = "",val;
    getline(cin,val);
    for(int i =0 ; i < n; i++){
        cout << fields[i];
        getline(cin,val);
        s += val;
        if(i!=n-1) s += " ";
    }
    return s;
}

stringstream input(int n, string fields[]){
    return stringstream("-1 "+input_str(n, fields));
}

void add(string op, Roles role, int pos = -1){
    clear();
    if(op == "user" && role == ADMIN){
        User obj;
        string arr[] = {"Name: ", "Email: ", "Password: ","Role(0-2): "};
        input(4, arr) >> obj;
        users.push(obj, pos);
    }
    else if(op == "book"){
        Book obj;
        string arr[] = {"Book Type(0-1): ", "Name: ", "Year: ", "Gener(0-8): ","Pages: ","Author Id: ","Publisher Id: "};
        input(7, arr) >> obj;
        books.push(obj, pos);
    }
    else if(op == "library" && role == ADMIN){
        Library obj;
        string arr[] = {"Name: ", "Address: ", "Duration: "};
        input(3, arr) >> obj;
        libraries.push(obj, pos);
    }
    else if(op == "publisher" && role == ADMIN){
        Publisher obj;
        string arr[] = {"Name: ", "Email: "};
        input(2, arr) >> obj;
        publishers.push(obj, pos);
    }
    else if(op == "author" && role == ADMIN){
        Author obj;
        string arr[] = {"First Name: ", "Last Name: "};
        input(2, arr) >> obj;
        authors.push(obj, pos);
    }
    else if(op == "lbook"){
        LibraryBook obj;
        string arr[] = {"Amount: ", "Library Id: ", "Book Id: "};
        input(3, arr) >> obj;
        lbooks.push(obj, pos);
    }
    else if(op == "order"){
        Order2 obj;
        string arr[] = {"User Id: ", "LBook Id: ", "Data: "};
        input(3, arr) >> obj;
        orders.push(obj, pos);
    }
    else throw "invalid object name";
}

void find(string op, int id ,Roles role)
{
    clear();
    if(id == -1)
    {
        if(op == "user" && role == ADMIN){
            for(auto it: users.get_map())
                cout << it.second << endl;
        }
        else if(op == "book"){
            for(auto it: books.get_map())
                cout << it.second << endl;
        }
        else if(op == "library"){
            for(auto it: libraries.get_map())
                cout << it.second << endl;
        }
        else if(op == "publisher"){
            for(auto it: publishers.get_map())
                cout << it.second << endl;
        }
        else if(op == "author"){
            for(auto it: authors.get_map())
                cout << it.second << endl;
        }
        else if(op == "lbook"){
            for(auto it: lbooks.get_map())
                cout << it.second << endl;
        }
        else if(op == "order"){
            for(auto it: orders.get_map())
                cout << it.second << endl;
        }
        else throw "invalid object name";

        cout << "\nPress any key...";
        getchar();
        getchar();
        return;
    }
    if(op == "user" && role == ADMIN){
        cout << users.get_by_id(id) << endl;
    }
    else if(op == "book"){
        cout << books.get_by_id(id) << endl;
    }
    else if(op == "library"){
        cout << libraries.get_by_id(id) << endl;
    }
    else if(op == "publisher"){
        cout << publishers.get_by_id(id) << endl;
    }
    else if(op == "author"){
        cout << authors.get_by_id(id) << endl;
    }
    else if(op == "lbook"){
        cout << lbooks.get_by_id(id) << endl;
    }
    else if(op == "order"){
        cout << orders.get_by_id(id) << endl;
    }
    else throw "invalid object name";

    cout << "\nPress any key...";
    getchar();
    getchar();
}




void librarian(){
    string s = "Posible commands:\n    add\n    find\n    change\n    exit\n\nCommand: ";
    vector<pair<string,function<void()>>> commands;
    commands.emplace_back("add",[](){
        string operand;
        cin >> operand;
        add(operand, LIBRARIAN);
    });
    commands.emplace_back("find",[](){
        string operand, id;
        cin >> operand >> id;
        int i;
        if(id == "all")
            i = -1;
        else
            i = stoi(id);
        find(operand, i, LIBRARIAN);
    });
    commands.emplace_back("change",[](){
        string operand, id;
        cin >> operand >> id;
        add(operand, LIBRARIAN, stoi(id));
    });

    commander(commands,s);
};
#endif
