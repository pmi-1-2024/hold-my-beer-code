#ifndef ORDER
#define ORDER
#include <iostream>
#include <string>

using namespace std;

class Order {
private:
    int id;
    string begining_date;
    int user_libery_id;
    int library_book_id;

public:
    
    Order() : id(0), begining_date(""), user_libery_id(0), library_book_id(0) {}

    
    Order(int id, const string& begining_date, int user_libery_id, int library_book_id)
        : id(id), begining_date(begining_date), user_libery_id(user_libery_id), library_book_id(library_book_id) {}

   
    int get_id() const { return id; }
    string getBeginingDate() const { return begining_date; }
    int getUserLiberyId() const { return user_libery_id; }
    int getLibraryBookId() const { return library_book_id; }

   
    void set_id(int newId) { id = newId; }
    void setBeginingDate(const string& newDate) { begining_date = newDate; }
    void setUserLiberyId(int newUserLibId) { user_libery_id = newUserLibId; }
    void setLibraryBookId(int newBookId) { library_book_id = newBookId; }

   
    void print(ostream& os) const {
        os << id << " " << begining_date << " " << user_libery_id << " " << library_book_id;
    }
   
    void read(istream& is) {
        is >> this->id >> this->begining_date >> this->user_libery_id >> this->library_book_id;
    }


    friend ostream& operator<<(ostream& os, const Order& order) {
        order.print(os);
        return os;
    }


    friend istream& operator>>(istream& is, Order& order) {
        order.read(is);
        return is;
    }
};
#endif