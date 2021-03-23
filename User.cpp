#include "User.h"
using namespace std;
User::User()//default constructor
{
    name="";
    id=0;
    age=0;
    password="";
    email="";
    count++;
    id=count;
}
User:: User(string name, int age, string email, string password) //Parameterize constructor
{
     this->name=name;
     this->age=age;
     this->email=email;
     this->password=password;
      id=0;
     count++;
    id=count;
}
User:: User(const User&user) //Copy constructor
{
     name= user.name;
     age=user.age;
     email=user.email;
     password=user.password;
     id=user.id;
}
 bool User:: operator==(const User& user) //Operator overloading
 {
      if(name==user.name &&email==user.email&&age==user.age&&id==user.id)
      {
           return 1;
      }
      return 0;
 }
 void User:: setName(string name) //Setter
 {
      this->name=name;
 }
 string User:: getName() const //getter
 {
      return name;
 }
 void User::setPassword(string password)
 {
      this->password= password;
 }
 string User::getPassword()const
 {
      return password;
 }
 void User::setEmail(string email)
 {
     this->email=email;
 }
 string User:: getEmail()const
 {
      return email;
 }
void User::setAge(int age)
{
     this->age=age;
}
 int User:: getAge()const
 {
      return age;
 }
 void User::setId(int id)
 {
      this->id=id;
 }
 int User::getId()const
 {
      return id;
 }
  ostream &operator<<(ostream &output, const User &user ) //operator overloading
 {
      output<<"========User "<<user.getId()<<"  info ========"<<endl;
      output<<"Name: "<<user.getName()<<"|Age: "<<user.getAge()<<"|Id: "<<user.getId()<<"|Email: "<<user.getEmail();
      return output;
 }
 istream &operator>>( istream &input, User &user ) //operator overloading
 {
      cout<<"Enter the user information in this order"<<endl;
      cout<<"Name Age Email Password(Space Separated)"<<endl;
      input>>user.name>>user.age>>user.email>>user.password;
      return input;
 }

int User::count=0;
