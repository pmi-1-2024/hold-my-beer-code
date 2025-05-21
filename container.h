#ifndef CONTAINER
#define CONTAINER

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

template <class T>
class Container{
    map<int,T> data;
    int next_id = 0;
    string src;

public:

    Container(string src){
        this->src = src;
    }

    void push(T obj, int pos = -1){
        if(pos >= next_id) throw "Wrong Id";
        if (pos >= 0)
            data[pos] = obj;
        else
            data.insert({next_id++,obj});
    }

    void save(){
        ofstream file(src);
        for(auto& p: data) file<<p.second <<endl;
        file.close();
    }

    void load(){
        ifstream file(src);
        string s;
        T obj;

        getline(file,s);
        while(!file.eof()){
            istringstream is(s);

            is >> obj;
            next_id = obj.get_id()+1;
            push(obj,obj.get_id());
        }
    }

    T& get_by_id(int id){
        if(id >= next_id) throw "Wrong Id";
        return data[id];
    }

    map<int, T>& get_map(){
        return data;
    }
};

#endif