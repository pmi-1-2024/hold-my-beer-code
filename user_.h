#ifndef USER_
#define USER_
#include "commander.h"
#include <iostream>
#include <functional>
#include <vector>
#include <ctime>
#include "validations.h"
#include "data.h"
#include "enums.h"

void Books(){
  clear();
   for(auto it: lbooks.get_map()){
      cout<<"Id: "<<it.second.get_id()<<"    Amout_of_books: "<<it.second.getAmountOfBooks()<<"    Library: "<<libraries.get_by_id(it.second.getLibraryId()).get_name()<<"    Book: "<<books.get_by_id(it.second.getBookId()).get_book_type()<<" "<<books.get_by_id(it.second.getBookId()).get_name()<<" "<<books.get_by_id(it.second.getBookId()).get_year()<<" " << books.get_by_id(it.second.getBookId()).get_gener()<<" "<<books.get_by_id(it.second.getBookId()).get_pages()<<"    Author : "<<authors.get_by_id(books.get_by_id(it.second.getBookId()).get_author_id()).get_last_name()<<"    Publisher : "<<publishers.get_by_id(books.get_by_id(it.second.getBookId()).get_publisher_id()).get_name()<<endl;
   }
  cout << "\nPress any key...";
  getchar();
  getchar();
}

void History(int session_id){
  clear();
  bool found = false;
  for (auto& p : orders.get_map()) {
    if(p.second.getUserLiberyId()==session_id) {
      cout <<"Order ID: "<< p.first
           <<"    Name: "<< books.get_by_id(lbooks.get_by_id(p.second.getLibraryBookId()).getBookId()).get_name()
           <<"    Date: "<< p.second.getBeginingDate()<<endl;
     found = true;
      
    }
  }
  if (!found) {
        cout << "No orders found "<<endl;
    }
  cout << "\nPress any key...";
  getchar();
  getchar();
}

void order(int session_id){
    clear();
        Order2 obj;
        int bi;
        cout << "Book Id: ";
        cin >> bi;

        time_t rawtime;
        char buff[50];
        time(&rawtime);
        strftime(buff, 50, "%F", gmtime(&rawtime));
        string time = buff;

        stringstream("-1 "+time+" "+to_string(session_id)+" "+to_string(bi)) >> obj;
        orders.push(obj);

}


void user(int session_id){
  string s = "Posible commands:\n    order\n    books\n    history\n    exit\n\nCommand: ";
  vector<pair<string,function<void()>>> commands;
  commands.emplace_back("order",[&](){order(session_id);});
  commands.emplace_back("books",[](){Books();});
  commands.emplace_back("history",[&](){History(session_id);});
  commander(commands,s);
}

#endif
