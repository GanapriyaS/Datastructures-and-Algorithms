#include<iostream>
using namespace std;

float area(float r)
{
return 3.14*r*r;
}

float area(float a,float b)
{
return 0.5*a*b;
}

int main ()
{   
    float r,a,b;
    cout<<"Enter radius of a circle : ";
    cin>>r;
    cout<<"Area of the Circe : "<<area(r);
    cout<<"\nEnter length and breadth of the triangle \n";
    cout<<"Length : ";
    cin>>a;
    cout<<"Breadth : ";
    cin>>b;
    cout<<"Area of the triangle : "<<area(a,b)<<endl;


    return 0;
}