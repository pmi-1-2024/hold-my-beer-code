#include <iostream>
#include <string>

using namespace std;

class LibraryBook {
private:
    int id;
    int amount_of_books;
    int library_id;
    int book_id;

public:
    
    LibraryBook() : id(0), amount_of_books(0), library_id(0), book_id(0) {}

    
    LibraryBook(int id, int amount_of_books, int library_id, int book_id)
        : id(id), amount_of_books(amount_of_books), library_id(library_id), book_id(book_id) {}

   
    int get_id() const { return id; }
    int getAmountOfBooks() const { return amount_of_books; }
    int getLibraryId() const { return library_id; }
    int getBookId() const { return book_id; }

    
    void setId(int newId) { id = newId; }
    void setAmountOfBooks(int amount) { amount_of_books = amount; }
    void setLibraryId(int libId) { library_id = libId; }
    void setBookId(int bId) { book_id = bId; }

    
    void print(ostream& os) const {
        os << id << " " << amount_of_books << " " << library_id << " " << book_id;
    }

    void read(istream& is) {
        is >> this->id >> this->amount_of_books >> this->library_id >> this->book_id;
    }
    
    friend ostream& operator<<(ostream& os, const LibraryBook& lb) {
        lb.print(os);
        return os;
    }

    friend istream& operator>>(istream& is, LibraryBook& lb) {
        lb.read(is);
        return is;
    }
};
