#ifndef DATA
#define DATA
#include "container.h"
#include "structures.h"

Container<Author> authors("data/authors.csv", "id,first_name,last_name");
Container<Publisher> publishers("data/publishers.csv", "id,name,email");
Container<Book> books("data/books.csv", "id,book_type,name,year,gener,pages,author_id,publisher_id");
Container<Library> libraries("data/libraries.csv", "id,name,address,duration");
Container<User> users("data/users.csv", "id,name,email,password,role");
Container<LibraryBook> lbooks("data/lbooks.csv", "id,amount_of_books,library_id,book_id");
Container<Order> orders("data/orders.csv", "id,user_id,lbook_id,date");

void load(){
    authors.load();
    publishers.load();
    books.load();
    libraries.load();
    users.load();
    lbooks.load();
    orders.load();
}

void save(){
    authors.save();
    publishers.save();
    books.save();
    libraries.save();
    users.save();
    lbooks.save();
    orders.save();
}

#endif