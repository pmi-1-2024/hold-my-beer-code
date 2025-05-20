#ifndef CMD
#define CMD
#include <iostream>
#include <functional>
#include <vector>
#include <ctime>
#include "data.h"
#include "validations.h"
#include "fout.h"
using namespace std;
void menu();
void admin(int session_id);
void librarian(int session_id);
void user(int session_id);

void clear(){
    int a = system("cls");
        if(a != 0) system("clear"); // this command for linux for Window you should use system("cls");
}

string input_str(int n, string fields[]){
    string s = "",val;
    getline(cin,val);
    for(int i =0 ; i < n; i++){
        cout << fields[i];
        getline(cin,val);
        s += val;
        if(i!=n-1) s += ",";
    }
    return s;
}

stringstream input(int n, string fields[]){
    return stringstream(input_str(n, fields));
}

void sign(){
    clear();
    cout << "Sign In\n\n";  
    
    User u;
    string arr[] = {"Name: ", "Email: ", "Password: "};
    stringstream(input_str(3, arr)+",0") >> u;

    Roles role;
    int id = -1;

    for(auto p: users.give_map())
        if(p.second.email == u.email){
            if(p.second.name == u.name & p.second.password == u.password){
                role = p.second.role;
                id = p.first;
            }
            else throw "Either the name or password is incorrect";
            break;
        }
    
    if(id == -1) throw "Such an acount does not exist";
    
    switch(role){
        case ADMIN:
            admin(id);
            break;
        case LIBRARIAN:
            librarian(id);
            break;
        case USER:
            user(id);
            break;
    }
}

void reg(){
    clear();
    cout << "Registration\n\n";

    User u;
    string arr[] = {"Name: ", "Email: ", "(At least 8 characters, upperscale letter, lowerscale letter, one digit and one special character)\nPassword: "};
    stringstream(input_str(3, arr)+",2") >> u;

    for(auto p: users.give_map())
        if(p.second.email == u.email) throw "Account with such an email already exists";
    
    users.push(u);
    throw "You have successfully registered";
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
        Order obj;
        string arr[] = {"User Id: ", "LBook Id: ", "Data: "};
        input(3, arr) >> obj;
        orders.push(obj, pos);
    }
    else throw "invalid object name";
}

void find(string op, string id, Roles role){
    clear();
    fout output(cout, 45);
    auto check = [](string id, int toch){return  id == "all" or id == to_string(toch);};

    if(op == "user" && role == ADMIN) for(auto p: users.give_map()){if(check(id,p.first)) output << p.first << p.second.name<< p.second.email<< p.second.password<< p.second.role<<endl;} 
    else if(op == "book") for(auto p: books.give_map()){if(check(id,p.first))output<< p.first << p.second.bt << p.second.name << p.second.year << p.second.gener << p.second.pages << authors.get_by_id(p.second.author_id).last_name+"("+to_string(p.second.author_id)+")" << publishers.get_by_id(p.second.publisher_id).name+"("+to_string(p.second.publisher_id)+")"<<endl;}
    else if(op == "library") for(auto p: libraries.give_map()){if(check(id,p.first))output<< p.first << p.second.name << p.second.address << p.second.duration<<endl;}
    else if(op == "publisher") for(auto p: publishers.give_map()){if(check(id,p.first))output<< p.first << p.second.name  << p.second.email<<endl;}
    else if(op == "author") for(auto p: authors.give_map()){if(check(id,p.first))output<< p.first << p.second.first_name << p.second.last_name<<endl;}
    else if(op == "lbook") for(auto p: lbooks.give_map()){if(check(id,p.first)) output<< p.first << p.second.amount_of_books << p.second.library_id << p.second.book_id<<endl;} //
    else if(op == "order") for(auto p: orders.give_map()){if(check(id,p.first)) output<< p.first << p.second.user_id << p.second.lbook_id << p.second.date<<endl;}              //
    else throw "invalid object name";
    cout << "\nPress any key...";
    getchar();
    getchar();
}

void commander(vector<pair<string,function<void()>>> comands, string mline, string msg = ""){
    string command;
    bool invalid;
    while(true){
        try{
            clear();
            cout << msg <<"\n\n";
            msg = "";
            invalid = true;
            cout << mline;
            cin >> command;
            if(command == "exit") break;
            for(auto p: comands)
                if(command == p.first){
                    p.second();
                    invalid = false;
                    break;
            }
            if(invalid) throw "Wrong command";
        }
        catch(char const* e){msg = e;}
        catch(invalid_argument& e){msg = "You cannot use string for int var";}
    }
}

void admin(int session_id){
    string mline = "Posible commands:\n    add\n    find\n    change\n    exit\n\nCommand: ";
    vector<pair<string,function<void()>>> commands;
    commands.emplace_back("add",[](){
        string operand;
        cin >> operand;
        add(operand, ADMIN);
    });
    commands.emplace_back("find",[](){
        string operand, id;
        cin >> operand >> id;
        find(operand, id, ADMIN);
    });
    commands.emplace_back("change",[](){
        string operand, id;
        cin >> operand >> id;
        add(operand, ADMIN, stoi(id));
    });

    commander(commands,mline);
};

void librarian(int session_id){
    string mline = "Posible commands:\n    add(order,lbook,book)\n    find\n    change(order,lbook,book)\n    close\n    exit\n\nCommand: ";
    vector<pair<string,function<void()>>> commands;
    commands.emplace_back("add",[](){
        string operand;
        cin >> operand;
        add(operand, LIBRARIAN);
    });
    commands.emplace_back("find",[](){
        string operand, id;
        cin >> operand >> id;
        find(operand, id, LIBRARIAN);
    });
    commands.emplace_back("change",[](){
        string operand, id;
        cin >> operand >> id;
        add(operand, LIBRARIAN, stoi(id));
    });
    commands.emplace_back("close",[](){
        string c;
        cin >> c;
        int id = stoi(c);
        auto it = orders.give_map().find(id);
        if (it == orders.give_map().end())  throw "Wrong Id";
        lbooks.get_by_id((*it).second.lbook_id).amount_of_books ++;
        orders.give_map().erase(it);
        
    });

    commander(commands,mline);
}

void user(int session_id){
    string mline = "Posible commands:\n    order\n    books\n    history\n    exit\n\nCommand: ";
    vector<pair<string,function<void()>>> commands;
    commands.emplace_back("order",[&](){
        clear();
        cout << "Book Id: ";
        string sid;
        cin >> sid;
        int id = stoi(sid);
        Order o;
        o.user_id = session_id;
        o.lbook_id = id;
        if(lbooks.get_by_id(id).amount_of_books <=0 ) throw "This books is not available at the moment";
        lbooks.get_by_id(id).amount_of_books --;
        time_t rawtime;
        char buff[50];
        time(&rawtime);
        strftime(buff, 50, "%F", gmtime(&rawtime));
        o.date = buff;
        orders.push(o);
    });
    commands.emplace_back("books",[](){

        clear();
        fout output(cout, 45);
        for(auto p: lbooks.give_map()){
            Book book = books.get_by_id(p.second.book_id);
            output << p.first << p.second.amount_of_books;
            output << book.name << to_string(book.year) +", "+ to_string(book.gener)+", "+to_string(book.pages)+", "+authors.get_by_id(book.author_id).last_name+", "+publishers.get_by_id(book.publisher_id).name;
            output << libraries.get_by_id(p.second.library_id).name;
            output << endl;
        }
        cout << "\nPress any key...";
        getchar();
        getchar();
    });
    commands.emplace_back("history",[&](){
        clear();
        fout output(cout, 45);
        LibraryBook lbook;
        Book book;
        Library lib;
        for(auto p: orders.give_map()) 
            if(p.second.user_id == session_id){
                lbook = lbooks.get_by_id(p.second.lbook_id);
                book = books.get_by_id(lbook.book_id);
                lib = libraries.get_by_id(lbook.library_id);
                output<< book.name << lib.name << p.second.date<< "Duration: "+to_string(lib.duration)+" month" <<endl;
            }
        cout << "\nPress any key...";
        getchar();
        getchar();

    });

    commander(commands,mline);
};

void menu(){

    string mline = "Posible commands:\n    reg\n    sign\n    exit\n\nCommand: ";
    vector<pair<string,function<void()>>> commands;
    commands.emplace_back("reg",[](){reg();});
    commands.emplace_back("sign",[](){sign();});

    commander(commands,mline);
}

#endif