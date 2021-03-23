#ifndef BOOKLIST_H
#define BOOKLIST_H
#include "User.h"
#include"Book.h"
#include "UserList.h"
class BookList
{
    private:
 int capacity;
 int booksCount;
 public:
 Book* books;
 BookList(const BookList& anotherList);
 BookList(int capacity);
 Book* searchBook(string name);
 Book* searchBook(int id);
 void deleteBook(int id); //delete a book
 Book getTheHighestRatedBook();
 Book* getBooksForUser(User); // get all books of this author
 Book & operator [] (int position);
 friend ostream &operator<<( ostream &output, BookList &booklist ); //to display all books
  void addBook(Book book);
 ~BookList();

};

#endif // BOOKLIST_H
