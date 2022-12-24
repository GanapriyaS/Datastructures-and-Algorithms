#include<iostream>
using namespace std;

class ABC{
int a;
int b;
public:
void setvalue(int i,int j){ a=i;b=j; }
friend float mean(ABC);
};


float mean(ABC abc){
    return float(abc.a + abc.b)/2.0;
}
int main(){
    ABC abc;
    abc.setvalue(4,5);
    cout<<"Mean value : "<<mean(abc)<<endl;
    return 0;
}