#include"Book.h"
#include "User.h"
using namespace std;
Book::Book()//default constructor
{
    title="";
    id=0;
    checkAuthor=0;
    isbn="";
    category="";
    averageRating=0.0;
    count++;
    id=count;
    TotalRating=0;
    countNumberRating=0;
}
Book:: Book(string title, string isbn, string category) //Parameterize constructor
{
     this->title=title;
     this->isbn=isbn;
     this->category=category;
      averageRating=0.0;
      id=0;
     count++;
    id=count;
    TotalRating=0;
        countNumberRating=0;
}
Book::  Book(const Book& book) //Copy constructor
{
     title= book.title;
     isbn=book.isbn;
     category=book.category;
     averageRating=book.averageRating;
     id=book.id;
     author=book.author;
}
 bool Book:: operator==(const Book& book) //Operator overloading
 {
      if(title==book.title &&isbn==book.isbn&&category==book.category&&id==book.id)
      {
           return 1;
      }
      return 0;
 }
void Book::setTitle(string title)
{
     this->title=title;
}
 string Book:: getTitle() const
 {
      return title;
 }
 void Book:: setISBN(string isbn)
 {
      this->isbn=isbn;
 }
 string  Book::getISBN() const
 {
      return isbn;
 }
 void Book::setId(int id)
 {
      this->id=id;
 }
 int Book:: getId() const
 {
      return id;
 }
 void Book::setCategory(string category)
 {
      this->category=category;
 }
 string Book:: getCategory() const
 {
      return category;
 }
 void Book:: setAuthor(User user)
 {
      author = user;
     checkAuthor=1;
 }
 User Book:: getAuthor() const
 {
      return author;
 }
 void Book:: rateBook(int rating)
 {
      countNumberRating++;
      TotalRating+=rating;
       averageRating = double(TotalRating)/countNumberRating;
 }
ostream &operator<<(ostream &output, const Book &book )
{
      output<<"========Book "<<book.getId()<<"  info ========"<<endl;
      output<<"Title: "<<book.getTitle()<<"|ISBN: "<<book.getISBN()<<"|Id: "<<book.getId()<<"|Category: "<<book.getCategory()<<"|AverageRating: "<<book.averageRating<<endl;
      if(book.checkAuthor &&book.author.getName()!="")
      {
           cout<<book.author<<endl;
      }

      return output;

}
istream &operator>>( istream &input, Book &book )
{
      cout<<"Enter the book information in this order"<<endl;
      cout<<"Title ISBN  Category"<<endl;
      input>>book.title>>book.isbn>>book.category;
      return input;
}

int Book::count=0;

