#include "UserList.h"
#include "User.h"
UserList::UserList(int capacity)
{
    this->capacity= capacity;
    users = new User [this->capacity];
    usersCount =0;
}

void UserList::addUser(User user)
{

           users[usersCount].setName(user.getName());
            users[usersCount].setAge(user.getAge());
             users[usersCount].setEmail(user.getEmail());
              users[usersCount].setPassword(user.getPassword());
               users[usersCount].setId(usersCount+1);
            usersCount++;

}
User* UserList:: searchUser(int id)
{
     for(int i=0;i<usersCount;i++)
     {
          if(users[i].getId() == id)
          {
               return &users[i];
          }
     }
     return nullptr ;
}
 User* UserList::  searchUser(string name)
 {
       for(int i=0;i<usersCount;i++)
     {
          if(users[i].getName() ==name)
          {
               return &users[i];
          }
     }
     return nullptr ;
 }
void UserList:: deleteUser(int id)
{
     for(int i=id-1;i<usersCount-1;i++)
     {
          users[i] = users[i+1];
          users[i].setId(users[i+1].getId());
     }
     users[usersCount].setId(0);
    usersCount--;
}
 ostream &operator<<( ostream &output, UserList &userList )
{
     for(int i=0;i<userList.usersCount;i++)
     {
          output<<userList.users[i]<<endl;
     }
     return output;
}
UserList:: ~UserList()
{
     delete [] users;
}


