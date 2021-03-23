#include "BookList.h"
#include "User.h"
#include"Book.h"
#include "UserList.h"
 BookList:: BookList(int capacity)
 {
     this->capacity = capacity;
     books = new Book [this->capacity];
     booksCount=0;
 }
  BookList::BookList(const BookList& anotherList)
{
     capacity = anotherList.capacity;
     booksCount =anotherList.booksCount;
     books = new Book [capacity];
     for(int i=0;i< booksCount;i++)
     {
          books[i]= anotherList.books[i];
     }
}
Book* BookList :: searchBook(int id)
{
     for(int i=0;i<booksCount;i++)
     {
          if( books[i].getId() == id)
          {
               return &books[i];
          }
     }
     return nullptr ;
}
 Book* BookList::searchBook(string name)
 {
       for(int i=0;i<booksCount;i++)
     {
          if(books[i].getTitle() ==name)
          {
               return &books[i];
          }
     }
     return nullptr ;
 }
 void  BookList:: deleteBook(int id)
{
     for(int i=id-1;i<booksCount-1;i++)
     {
          books[i] = books[i+1];
          books[i].setId(books[i+1].getId());
     }
     books[booksCount].setId(0);
   booksCount--;
}
 Book BookList:: getTheHighestRatedBook()
 {
      double maxRate =0.0 ;
       int maxRateIndex=0;
      for(int i=0;i<booksCount;i++)
      {
           if(maxRate < books[i].averageRating)
           {
                 maxRateIndex = i;
           }
      }
      return books[maxRateIndex];
 }
 Book* BookList:: getBooksForUser(User u)
 {
      Book *booksWithCommonUser = new Book [booksCount];
      int countCommon =0;
      for(int i=0;i<booksCount;i++)
      {
           if(books[i].getAuthor()==u)
           {
                booksWithCommonUser[countCommon] = books[i];
                countCommon++;
           }
      }
      if(countCommon !=0)
      {
           return booksWithCommonUser;
      }
      return nullptr;
 }
 Book &  BookList:: operator [ ] (int position)
 {
      if(position <0)
      {
           cout<<"Wrong Position ,Please enter the right position"<<endl;
      }
      else
      {
           return books[position];
      }
 }
 ostream &operator<<( ostream &output, BookList &booklist )
 {
       for(int i=0;i<booklist.booksCount;i++)
     {
          output<<booklist.books[i]<<endl;
     }
     return output;
 }
  void BookList:: addBook(Book book)
  {
          books[booksCount].setTitle(book.getTitle());
          books[booksCount].setCategory(book.getCategory());
          books[booksCount].setISBN(book.getISBN());
          booksCount++;
  }
 BookList:: ~BookList()
{
     delete [] books;
}
