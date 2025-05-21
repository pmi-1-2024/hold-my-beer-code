#include <bits/stdc++.h>
using namespace std;

class Publisher{
    private:
        int id;
        string name;
        string email;
    public:
        Publisher()
        {
            id = 0;
            name = "";
            email = "";
        }
        Publisher(int i, string f, string l)
        {
            id = i;
            name =f;
            email = l;
        }
        int get_id()
        {
            return id;
        }
        string get_name()
        {
            return name;
        }
        string get_email(){
            return email;
        }
        void set_id(int i)
        {
            id = i;
        }
        void set_name(string f)
        {
            name =f;
        }
        void set_email(string l)
        {
            email = l;
        }
        void print(ostream& out)
        {
            out << id <<' '<< name << ' ' << email;
        }
        void input(istream& in)
        {
            in >> id >> name >> email;
        }
        friend istream& operator>>(istream& inp, Publisher& obj)
        {
            obj.input(inp);
            return inp;
        }
        friend ostream& operator<<(ostream& out, Publisher& obj)
        {
            obj.print(out);
            return out;
        }
};
