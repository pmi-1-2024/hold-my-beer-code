#ifndef DATA
#define DATA
#include "container.h"
#include "book.h"
#include "library.h"
#include "author.h"
#include "publisher.h"
#include "user.h"
#include "library_book.h"
#include "order.h"

Container<Author> authors("data/authors.txt");
Container<Publisher> publishers("data/publishers.txt");
Container<Book> books("data/books.txt");
Container<Library> libraries("data/libraries.txt");
Container<User> users("data/users.txt");
Container<LibraryBook> lbooks("data/lbooks.txt");
Container<Order2> orders("data/orders.txt");

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