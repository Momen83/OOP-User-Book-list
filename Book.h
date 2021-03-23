#ifndef BOOK_H
#define BOOK_H
#include<cstring>
#include<iostream>
#include "User.h"
using namespace std;
class Book
{
private:
 string title;
 string isbn;
 int id; // Make sure that the id is incremental. First id is 1, second is 2 and so on
 string category;
 bool checkAuthor; //check if Author is founded or not
 // this variable should contain the average rating for the book, rateBook function
 // should update this attribute with the new average rating for the book
 int TotalRating;
  int countNumberRating;
 User author;
public:
double averageRating;
static int count;
 Book();
 Book(string title, string isbn, string category);
 Book(const Book& book);
 void setTitle(string title);
 string getTitle() const;
 void setISBN(string isbn);
 string getISBN() const;
 void setId(int id);
 int getId() const;
 void setCategory(string category);
 string getCategory() const;
 void setAuthor(User user);
 User getAuthor() const;
 void rateBook(int rating);
 bool operator==(const Book& book);
 friend ostream &operator<<(ostream &output, const Book &book );
 friend istream &operator>>( istream &input, Book &book );
};
#endif

