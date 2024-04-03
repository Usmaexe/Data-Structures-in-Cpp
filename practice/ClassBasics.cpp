#include <iostream>
#include <sstream>
#include <string>

using namespace std;
class Person{
  private :
    string name;
    int age;
  public:
    Person(string name,int age){
      this->name = name;
      this->age = age;
    }
    string getName(){
      return this->name;
    }
    int getAge(){
      return this->age;
    }
    void setName(string name){
      this->name = name;
    }
    void setAge(int age){
      this->age = age;
    }
    string toString(){
      stringstream iss;
      iss << "Name : " << this->name <<" Age : " << to_string(this->age);
      return iss.str();
    }
};

int main(){
  Person p("karim",18);
  p.setAge(20);
  cout << p.toString();


}