#ifndef AUTHOR
#define AUTHOR
#include <bits/stdc++.h>
using namespace std;

class Author{
    private:
        int id;
        string first_name;
        string last_name;
    public:
        Author()
        {
            id = 0;
            first_name = "";
            last_name = "";
        }
        Author(int i, string f, string l)
        {
            id = i;
            first_name =f;
            last_name = l;
        }
        int get_id()
        {
            return id;
        }
        string get_first_name()
        {
            return first_name;
        }
        string get_last_name()
        {
            return last_name;
        }
        void set_id(int i)
        {
            id = i;
        }
        void set_first_name(string f)
        {
            first_name =f;
        }
        void set_last_name(string l)
        {
            last_name = l;
        }
        void print(ostream& out)
        {
            out << id <<' '<< first_name << ' ' << last_name;
        }
        void input(istream& in)
        {
            in >> id >> first_name >> last_name;
        }
        friend istream& operator>>(istream& inp, Author& obj)
        {
            obj.input(inp);
            return inp;
        }
        friend ostream& operator<<(ostream& out, Author& obj)
        {
            obj.print(out);
            return out;
        }
};
#endif