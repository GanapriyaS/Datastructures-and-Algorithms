#include<iostream>
using namespace std;

class Rectangle{
  float lenght;
  float breadth;
  public:
    Rectangle(){
      cout<<"\n=======================\nDefault Constructor\n=======================\n";
       lenght=breadth=0;
    } 
    Rectangle(int l){
      lenght=breadth=l;
    } 
    Rectangle(float l,float b=10.0){
      cout<<"\n=======================\nDefault parameter\n=======================\n";
       lenght=l;
       breadth=b;
    }
      Rectangle(float l,int b){
      cout<<"\n=======================\nParameterized constructor\n=======================\n";
       lenght=l;
       breadth=b;
    }
    
  
    
    void area(){
        float area= lenght * breadth;
        cout<<"Area of the rectangle : "<< area <<"\n";
    }
};


int main(){
    float l=6.0;
    float b=8.0;
    Rectangle r;
    Rectangle r1(10);
    Rectangle r2(l,b);
    //  Rectangle r2(45.0,89.0);
    // Rectangle r3(20.9,10);
    r.area();
    r1.area();
    r2.area();
    // r3.area();
    return 0;
}