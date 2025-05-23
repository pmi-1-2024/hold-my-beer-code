#ifndef USER_
#define USER_
#include "commander.h"
#include <iostream>
#include <functional>
#include <vector>
#include "validations.h"
#include "data.h"
#include "enums.h"
void Order(){
  
}
void Books(){
  clear();
   for(auto it: lbooks.get_map()){
      cout<<"Id: "<<it.second.get_id()<<"Amout of books : "<<it.second.getAmountOfBooks()<<" Library : "<<libraries.get_by_id(it.second.getLibraryBookId()).get_name()<<" Book type : "<<books.get_by_id(it.second.getBookId()).get_book_type()<<" Name : "<<books.get_by_id(it.second.getBookId()).get_name()<<" Year : "<<books.get_by_id(it.second.getBookId()).get_year()<<" Gener : " << books.get_by_id(it.second.getBookId()).get_gener()<<" Pages :  "<<books.get_by_id(it.second.getBookId()).get_pages()<<" Author : "<<authors.get_by_id(books.get_by_id(it.second.getBookId()).get_author_id()).get_last_name()<<" Publisher : "<<publishers.get_by_id(books.get_by_id(it.second.getBookId()).get_publisher_id()).get_name()<<endl;
   }
  
}
void History(){
  clear();
  bool found = false;
  for (auto& p : orders.get_map()) {
    if(p.second.getUserLiberyId()==session_id) {
      cout <<" Order ID : "<<p.get_id() 
           <<" Name : "<< books.get_by_id(lbooks.get_by_id(p.second.getLibraryBookId()).getBookId()).get_name()
           <<" Date : "<< p.second.getBeginingDate()<<endl;
     found = true;
      
    }
  }
  if (!found) {
        cout << "No orders found "<<endl;
    }
}

void user(int session_id){
  string s = "Posible commands:\n    order\n    books\n    history/n    exit\n\nCommand: ";
  vector<pair<string,function<void()>>> commands;
  commands.emplace_back("order",[](){Order();});
  commands.emplace_back("books",[](){Books();});
  commands.emplace_back("history",[](){History(session_id);});
  commander(commands,s);
}
}
#endif
