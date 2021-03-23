#include <iostream>
#include "User.h"
#include"Book.h"
#include "UserList.h"
#include "BookList.h"
using namespace std;
void select()
{
     cout<<"Select one of the following choices"<<endl;
     cout<<"1- Book Menu"<<endl;
     cout<<"2- Users Menu"<<endl;
     cout<<"3- Exit"<<endl;
}
void userMenu()
{
     cout<<"USER MENU"<<endl;
     cout<<"1- Create a USER and add it to the list"<<endl;
     cout<<"2- Search for a user"<<endl;
     cout<<"3- Display all users"<<endl;
     cout<<"4- Back to the main menu"<<endl;
}
void searchUser()
{
     cout<<"SEARCH FOR A USER"<<endl;
     cout<<"1- Search by name"<<endl;
     cout<<"2- Search by id"<<endl;
     cout<<"3- Return to Users Menu"<<endl;

}
void bookMenu()
{
     cout<<"BOOK MENU"<<endl;
     cout<<"1- Create a book and add it to the list"<<endl;
     cout<<"2- Search for a book"<<endl;
     cout<<"3- Display all books (with book rating)"<<endl;
     cout<<"4- Get the highest rating book"<<endl;
     cout<<"5- Get all book of user "<<endl;
     cout<<"6- Copy the current Book list to a new Book List and switch to it "<<endl;
     cout<<"7- Back to the main menu"<<endl;
}
void searchBook()
{
     cout<<"SEARCH FOR A BOOK"<<endl;
     cout<<"1- Search by name"<<endl;
     cout<<"2- Search by id"<<endl;
     cout<<"3- Return to Books Menu"<<endl;

}
void  searchOptionss()
{
     cout<<"1-Update author "<<endl;
     cout<<"2- Update name"<<endl;
     cout<<"3- Update category"<<endl;
     cout<<"4- Delete Book"<<endl;
     cout<<"5- Rate book"<<endl;
     cout<<"6- Get to books menu"<<endl;
}
int main()
{
     int options,userCapacity,userOptions,userSearchOptions,userSearchOptions2,searchById,bookCapacity,bookOptions,bookSearchOptions,bookSearchOptions2;
       int usercount=0,countbooks=0,idSetter=1;
     string searchByName;
     UserList *UserslLi;
     BookList * booksll;
   while(true)
   {
        select();
        cin>>options;
        if(options==3)
        {
             break;
        }
        if(options==2)

       {
             cout<<"How many users will be added"<<endl;
             cin>>userCapacity;
             while(true)
             {
                   if(userCapacity>0)
                    {
                         UserslLi =new UserList (userCapacity);
                         break;
                    }
                    else
                    {
                         cout<<"Wrong Size ,Please Enter the correct size"<<endl;
                    }
             }

          while(true)
          {
               userMenu();

               cin>>userOptions;
               if(userOptions==1)
               {

                    User userr;
                    if(usercount<userCapacity)
                    {
                           cin>>userr;
                           UserslLi->addUser(userr);
                           usercount++;
                    }
                    else
                    {
                         cout<<"user list is full"<<endl;
                    }

               }
               if(userOptions==2)
               {
                    int check=0;
                   while(true)
                   {
                        if(check){break;}
                        searchUser();
                        cin>>userSearchOptions;
                        if(userSearchOptions==1)
                        {
                             cout<<"Enter Name"<<endl;
                             cin>>searchByName;
                             if( UserslLi->searchUser(searchByName)!= nullptr)
                             {
                                  cout<<*UserslLi->searchUser(searchByName)<<endl;
                                 cout<<"1- Delete user"<<endl;
                                 cout<<"2- Return to User Menu"<<endl;
                                 cin>>userSearchOptions2;
                                 if(userSearchOptions2==1)
                                 {
                                      UserslLi->deleteUser(UserslLi->searchUser(searchByName)->getId());
                                 }

                             }
                             else
                             {
                                  cout<<"The Name not found"<<endl;
                             }

                        }
                         if(userSearchOptions==2)
                        {
                             cout<<"Enter Id"<<endl;
                             cin>>searchById;
                             if( UserslLi->searchUser(searchById)!= nullptr)
                             {
                                  cout<<*UserslLi->searchUser(searchById)<<endl;
                                 cout<<"1- Delete user"<<endl;
                                 cout<<"2- Return to User Menu"<<endl;
                                 cin>>userSearchOptions2;
                                 if(userSearchOptions2==1)
                                 {
                                      UserslLi->deleteUser(UserslLi->searchUser(searchById)->getId());
                                 }

                             }
                             else
                             {
                                  cout<<"The Id not found"<<endl;
                             }

                        }
                        if(userSearchOptions==3)
                        {
                             check=1;
                             break;
                        }

                   }
               }
                if(userOptions==3)
                {
                     cout<<*UserslLi<<endl;
                }
                 if(userOptions==4)
                 {
                      break;
                 }
          }
        }
        if(options==1)
        {
             cout<<"How many books will be added"<<endl;
             cin>>bookCapacity;
               while(true)
             {
                   if(bookCapacity>0)
                    {
                         booksll =new BookList (bookCapacity);
                         break;
                    }
                    else
                    {
                         cout<<"Wrong Size ,Please Enter the correct size"<<endl;
                    }
             }
             while(true)
             {
                  bookMenu();
                  cin>>bookOptions;
                  if(bookOptions==1)
                  {
                       Book bookAdder;
                       if(countbooks <bookCapacity)
                       {
                             cin>>bookAdder;
                             booksll->addBook( bookAdder);
                             countbooks++;
                       }
                       else
                       {
                            cout<<"the book list is full"<<endl;
                       }

                    int assignAuthor=0;
                    while(true)
                    {
                         cout<<"1-Assign author"<<endl;
                         cout<<"2-Continue"<<endl;
                         cin>>assignAuthor;
                         if(assignAuthor==1)
                         {
                              int userID;
                              cout<<"Enter author (user) id:"<<endl;
                              cin>>userID;
                              if(UserslLi->searchUser(userID)==nullptr)
                              {
                                   cout<<"No Author found with id"<<userID<<endl;
                              }
                              else
                              {
                                   booksll->books[countbooks-1].setAuthor(*UserslLi->searchUser(userID));
                                   break;
                              }
                         }
                         else
                         {
                              break;
                         }
                    }

                  }
                  if(bookOptions==2)
                  {
                         int checks=1;
                            searchBook();
                              cin>>bookSearchOptions;
                            if(bookSearchOptions==1)
                         {
                           cout<<"Enter Name"<<endl;
                           cin>>searchByName;
                           if(booksll->searchBook(searchByName)!=nullptr)
                           {
                                cout<<*booksll->searchBook(searchByName)<<endl;
                           }
                           else
                           {
                                cout<<"Name not found"<<endl;
                                checks=0;
                           }
                         }
                         if(bookSearchOptions==2)
                         {
                           cout<<"Enter Id"<<endl;
                           cin>>searchById;
                           if(booksll->searchBook(searchById)!=nullptr)
                           {
                                cout<<*booksll->searchBook(searchById)<<endl;
                           }
                            else
                           {
                                cout<<"Id not found"<<endl;
                                 checks=0;
                           }
                         }
                         while(checks)
                         {
                              searchOptionss();
                         cin>>bookSearchOptions2;
                         if(bookSearchOptions2==1)
                         {
                              User userAdderr;
                              cin>>userAdderr;
                               userAdderr.setId(idSetter++);
                              if(bookSearchOptions==2)
                              {

                                    booksll->books[booksll->searchBook(searchById)->getId()-1].setAuthor(userAdderr);
                              }
                              if(bookSearchOptions==1)
                              {
                                    booksll->books[booksll->searchBook(searchByName)->getId()-1].setAuthor(userAdderr);
                              }

                         }
                         if(bookSearchOptions2==2)
                         {
                              string newName;
                              cout<<"Enter the New name"<<endl;
                              cin>>newName;
                              if(bookSearchOptions==2)
                              {
                                    booksll->books[booksll->searchBook(searchById)->getId()-1].setTitle(newName);
                              }
                              if(bookSearchOptions==1)
                              {
                                     booksll->books[booksll->searchBook(searchByName)->getId()-1].setTitle(newName);
                              }
                         }
                         if(bookSearchOptions2==3)
                         {
                              string newCategory;
                              cout<<"Enter the  new Category"<<endl;
                              cin>>newCategory;
                              if(bookSearchOptions==2)
                              {
                                    booksll->books[booksll->searchBook(searchById)->getId()-1].setCategory(newCategory);
                              }
                              if(bookSearchOptions==1)
                              {
                                     booksll->books[booksll->searchBook(searchByName)->getId()-1].setCategory(newCategory);
                              }
                         }
                          if(bookSearchOptions2==4)
                         {

                              if(bookSearchOptions==2)
                              {
                                    booksll->deleteBook(booksll->searchBook(searchByName)->getId());
                              }
                              if(bookSearchOptions==1)
                              {
                                      booksll->deleteBook(booksll->searchBook(searchById)->getId());
                              }
                         }
                         if(bookSearchOptions2==5)
                         {
                              double newRating;
                              cout<<"Enter the  new Rating Value"<<endl;
                              cin>>newRating;
                              if(bookSearchOptions==2)
                              {
                                    booksll->books[booksll->searchBook(searchById)->getId()-1].rateBook(newRating);
                              }
                              if(bookSearchOptions==1)
                              {
                                     booksll->books[booksll->searchBook(searchByName)->getId()-1].rateBook(newRating);
                              }
                         }
                         if(bookSearchOptions2==6)
                         {
                              break;
                         }
                         }

                  }
                  if(bookOptions==3)
                  {
                       cout<<*booksll<<endl;
                  }
                  if(bookOptions==4)
                  {
                       cout<<booksll->getTheHighestRatedBook()<<endl;
                  }
                   if(bookOptions==5)
                  {
                       cout<<"Enter user ID"<<endl;
                       int userID;cin>>userID;
                       Book *bookWithcomonUser ;
                     if( booksll->getBooksForUser(*UserslLi->searchUser(userID)) !=nullptr)
                     {
                          bookWithcomonUser = booksll->getBooksForUser(*UserslLi->searchUser(userID));
                          for(int i=0;i<countbooks;i++)
                          {
                               if( bookWithcomonUser[i].getTitle()!="")
                               {
                                    cout<<bookWithcomonUser[i]<<endl;
                               }
                          }
                     }
                     else
                     {
                          cout<<"No book found with user id = "<<userID<<endl;
                     }

                  }
                  if(bookOptions==6)
                  {
                       BookList CopyOfListOfBooks( *booksll);
                       cout<<"Copid current list ("<<countbooks<<") to a new list  and switched  to it"<<endl;
                  }
                   if(bookOptions==7)
                  {
                      break;
                  }

             }
        }
   }
}
