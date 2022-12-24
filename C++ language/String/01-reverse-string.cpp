#include<iostream>
#include<vector>
#include<Algorithm>
using namespace std;

// ----------------------------------------------------------------------------------------------------------------------- //
// method 1 - STL
string Solution1() {
    vector <char> s={'a','b','c','d','e'};
    reverse(s.begin(),s.end());
    for(int i=0;i<5;i++){
        cout<<s[i]<<" ";
    }
}


// ----------------------------------------------------------------------------------------------------------------------- //
// method 2
string Solution2(string s) {
    int j=s.length()-1;
    for(int i=0;i<j;i++,j--)
    {
        int temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
    return s;
}

// ----------------------------------------------------------------------------------------------------------------------- //
// method 3
string Solution3(string s) {
    int j=s.length()-1;
    for(int i=0;i<j;i++,j--)
    {
        swap(s[i],s[j]);
    }
    return s;
}

int main(){
    string s;
    cout<<"Enter string : ";
    cin>>s;
    cout<<"\nSolution 1 : ";
    Solution1();
    cout<<"\nSolution 2 : ";
    string s1= Solution3(s);
    cout<<s1;
    cout<<"\nSolution 3 : ";
    string s2=Solution2(s);
    cout<<s2;

    return 0;
}