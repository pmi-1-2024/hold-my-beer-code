#ifndef COMMANDER
#define COMMANDER

void clear(){
    int a = system("cls");
        if(a != 0) system("clear"); // this command for linux for Window you should use system("cls");
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

#endif
