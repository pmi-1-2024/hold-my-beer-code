#ifndef USER_
#define USER_
Order(){
  
}
Books(){
  clear();
  
}
History(){
  
}
void user(int session_id){
  string s = "Posible commands:\n    Order\n    Books\n    History/n    exit\n\nCommand: ";
  vector<pair<string,function<void()>>> commands;
  commands.emplace_back("Order",[](){Order();});
  commands.emplace_back("Books",[](){Books();});
  commands.emplace_back("History",[](){History();});
  commander(commands,s);
}
}
#endif
