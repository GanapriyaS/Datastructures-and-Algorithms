#include<iostream>
using namespace std;
class XYZ;

class ABC{
int a;
public:
void setvalue(int i){ a=i; }
friend void max(ABC,XYZ);
};


class XYZ{
int a;
public:
void setvalue(int i){ a=i; }
friend void max(ABC,XYZ);
};

void max(ABC abc,XYZ xyz){
    if(abc.a > xyz.a){
        cout<<abc.a<<endl;
    }
    else
    {
        cout<<xyz.a<<endl;
    }
}
int main(){
    XYZ xyz;
    ABC abc;
    xyz.setvalue(1);
    abc.setvalue(4);
    max(abc,xyz);
    return 0;
}