#include<iostream>
#include<Algorithm>
using namespace std;


// ----------------------------------------------------------------------------------------------------------------------- //
// method 1
int Solution1(string s)
{
		// Your code goes here
		int len = s.size();
		for (int i = 0;i < len / 2;i++) {
			if (s[i] != s[len - i - 1]) return 0;
		}
		return 1;
}	


// ----------------------------------------------------------------------------------------------------------------------- //
// method 2
int Solution2(string s)
	{
		// Your code goes here
		string temp = s;
		reverse(temp.begin(), temp.end());
		return (temp == s);
	}

int main(){
    string s;
    cout<<"Enter string : ";
    cin>>s;
    cout<<"\nSolution 1 : ";
    if(Solution1(s)) cout<<"Palindrome";
	else cout<<"Not palindrome";
    cout<<"\nSolution 2 : ";
    if(Solution2(s)) cout<<"Palindrome\n";
	else cout<<"Not palindrome\n";

    return 0;
}
