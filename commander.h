#ifndef COMMANDER
#define COMMANDER

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


void clear(){
    int a = system("cls");
        if(a != 0) system("clear"); // this command for linux for Window you should use system("cls");
}

void commander(vector<pair<string,function<void()>>> comands, string mline, string msg = ""){
    string command;
    bool invalid;
    cin.exceptions(ios::failbit);
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
        catch(invalid_argument& e){msg =  "You cannot use string value for int var";}
        catch(const ios_base::failure& e) {msg =  "You cannot use string value for int var";}
    }
}

#endif
