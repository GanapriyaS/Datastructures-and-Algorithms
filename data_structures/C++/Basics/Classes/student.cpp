#include<iostream>
using namespace std;

class Student{
  string name;
  public:
    Student(){
        name="Unknown";
    }  
    Student(string name){
        this->name=name;
    }
    void display(){
        cout<<"Name of the student : "<< name<<"\n";
    }
};


int main(){
    Student s;
    Student s1("Ram");
    s.display();
    s1.display();

    return 0;
}