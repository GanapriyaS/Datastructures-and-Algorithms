#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isOperator(char c)
{
    return c=='+'||c=='-'||c=='%'||c=='/'||c=='*'||c=='('||c=='^';
}
bool isOperand(char c)
{
    return (c>=65 && c<=90)||(c>=97 && c<=122);
}
int inPrecedence(char c)
{
    if(c=='+'||c=='-') return 2;
    if(c=='*'||c=='%'||c=='/')return 4;
    if(c=='^')return 5;
    if(c=='(')return 0;
    return 0;
}
int outPrecedence(char c)
{
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='%'||c=='/')return 3;
    if(c=='^')return 6;
    if(c=='(')return 7;
    return 100;
}
string infixToPostfix(string infix)
{
    stack<char>s;
    string postfix;
    for (char c : infix)
    {
        if(isOperand(c))
            postfix+=c;
        else if(c==')')
        {
            if(s.empty())
                  return "Wrong input";
            while(s.top()!='('&& !s.empty())
            {
                postfix=postfix+s.top();
                s.pop();
                if(s.empty())
                  return "Wrong input";
             }
           s.pop();
          }
          else if(isOperator(c))
          {
              if(s.empty()||outPrecedence(c)>inPrecedence(s.top()))
                  s.push(c);
              else
              {
                  while(!s.empty() && outPrecedence(c)<inPrecedence(s.top()))
                  {
                      postfix+=s.top();
                      s.pop();
                    }
                  s.push(c);
              }
          }
          else
          {
            return "INVALID EXPRESSION!";
          }
      }

      while(!s.empty())
    {
        postfix+=s.top();
        s.pop();
    }
    return  postfix;
}
int main()
{
      cout<<"1.INFIX INTO POSTFIX EXPRESSION CONVERSION"<<"\n"<<"0.EXIT"<<"\n";
      int ch;
      do {
      cout<<"_______________________________________________________________________________________________________"<<endl;
      cout<<"ENTER YOUR CHOICE:";
      cin>>ch;
      switch(ch)
      {
        case 0:
            cout<<"Exiting..........."<<endl;
            break;
        case 1:
        {
          string infix;
          cout<<"ENTER INFIX EXPRESSION:";
          cin>>infix;
          cout<<endl;
          cout<<"INFIX EXPRESSION:"<<infix<<endl;
          cout<<"POSTFIX EXPRESSION:"<<infixToPostfix(infix)<<endl;
          break;
        }
        default:
          cout<<"INVALID OPTION, TRY AGAIN!"<<endl;
      }
    } while(ch!=0);
return 0;
}
