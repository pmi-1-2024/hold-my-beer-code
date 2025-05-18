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
    string fields;

public:

    Container(string src, string fields){
        this->src = src;
        this->fields = fields;
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
        file << fields;
        for(auto& p: data) file << "\n" << p.first <<","<<p.second;
        file.close();
    }

    void load(){
        ifstream file(src);
        string s;

        getline(file,s);
        while(!file.eof()){
            string temp;
            int id;
            T obj;

            getline(file,s);
            istringstream is(s);

            getline(is,temp,',');
            istringstream(temp) >> id;
            is >> obj;
            push(obj);
            next_id = id+1;
        }
    }

    T get_by_id(int id){
        return data[id];
    }

    map<int, T> give_map(){
        return data;
    }
};

#endif