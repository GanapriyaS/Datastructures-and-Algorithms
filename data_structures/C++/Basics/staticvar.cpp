#include<iostream>
using namespace std;

class sample{
    static int count;
    int n;
    public:
    void getdata(int a){
        n=a;
        count++;
    }
    void getcount(){
        cout<<"count :"<<count<<"\nNumber :"<<n<<endl;
    }
};
int sample::count=9;
int main(){
    sample a,b,c;
    a.getcount();
    b.getcount();
    c.getcount();

    a.getdata(45);
    b.getdata(56);
    c.getdata(12);

    a.getcount();
    b.getcount();
    c.getcount();

    return 0;
}