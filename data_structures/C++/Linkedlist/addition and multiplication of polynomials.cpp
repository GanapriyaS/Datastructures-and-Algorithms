#include<iostream>
using namespace std;
class Node
{
    public:
        int coeff,exp;
        Node * next;
        Node()
        {
            coeff=exp=0;
            next=NULL;
        }
        Node(int coeff,int exp)
        {
            this->coeff=coeff;
            this->exp=exp;
            next=NULL;
        }

};
class polynomial
{
public:
      Node * head;
      polynomial()
      {
          head=NULL;
      }
      ~polynomial()
      {
           delete head;
       }
       void createNode();
       void removeDuplicate();
       void sortPower();
       void display();
       void add(polynomial &,polynomial &);
       void multiply(polynomial &,polynomial &);
};
void polynomial::createNode()
{
    delete head;
    head=NULL;
    char choice='z';
    do
    {
        Node * p=new Node();
        cout<<"ENTER THE COEFFICIENT:";
        cin>>p->coeff;
        cout<<"ENTER THE EXPONENT:";
        cin>>p->exp;
        if(head==NULL)
            head=p;
        else
        {
            Node * q=head;
            while(q->next)
                q=q->next;
            q->next=p;
        }
        do
        {
            cout<<"ENTER ANOTHER NODE?y/n :";
            cin>>choice;
            cout<<endl;
            if(choice!='y' && choice!='n')
                cout<<"INVALID CHOICE,TRY AGAIN!\n";
        }while(choice!='y' && choice!='n');
    }while(choice!='n');
    sortPower();
}
void polynomial::sortPower()
{
    if(head==NULL)
        return;
    Node * p=head;
    bool sorted=true;
    while(sorted)
    {
        sorted=false;
        Node *q=head;
        while(q->next!=NULL)
        {
            if(q->exp< q->next->exp)
            {
                int tempCoeff=q->coeff;
                int tempexp=q->exp;
                q->coeff=q->next->coeff;
                q->exp=q->next->exp;
                q->next->coeff=tempCoeff;
                q->next->exp=tempexp;
                sorted=true;
            }
            q=q->next;
        }
    }
}
void polynomial::removeDuplicate()
{
    Node *p=head;
    Node *q=p->next;
    while(q!=NULL)
    {
        if(p->exp!=q->exp)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->coeff=p->coeff+q->coeff;
            p->next=q->next;
            delete(q);
            q=p->next;
        }
    }
}
void polynomial::display()
{
    if(head==NULL)
        cout<<"POLYNOMIAL NOT SET!\n";
    else
    {
        Node *p=head;
        while(p)
        {
            cout<<p->coeff<<"x^"<<p->exp<<" ";
            if(p->next)
                cout<<"+ ";
            p=p->next;
        }
    }
}
void polynomial::multiply(polynomial & p1,polynomial & p2)
{
    if(!p1.head|| !p2.head)
    {
        if(!p1.head)
            cout<<"POLYNOMIAL 1 NOT SET!\n";
        if(!p2.head)
            cout<<"POLYNOMIAL 2 NOT SET!\n";
        return;
    }
    cout<<"POLYNOMIAL 1:";
    p1.display();
    cout<<"\nPOLYNOMIAL 2:";
    p2.display();
    Node *r=new Node();
    head=r;
    Node * p=p1.head;
    Node * q=p2.head;
    while(p)
    {
        q=p2.head;
        while(q)
        {
            r->coeff=p->coeff*q->coeff;
            r->exp=p->exp + q->exp;
            q=q->next;
            if(q)
            {
                r->next=new Node();
                r=r->next;
            }
        }
        p=p->next;
        if(p)
            {
                r->next=new Node();
                r=r->next;
            }
    }
    sortPower();
    removeDuplicate();
    cout<<"\nMULTIPLICATION OF 2 POLYNOMIALS:";
    display();
}
void polynomial::add(polynomial & p1,polynomial & p2)
{
    if(!p1.head|| !p2.head)
    {
        if(!p1.head)
            cout<<"POLYNOMIAL 1 NOT SET!\n";
        if(!p2.head)
            cout<<"POLYNOMIAL 2 NOT SET!\n";
        return;
    }
    cout<<"POLYNOMIAL 1:";
    p1.display();
    cout<<"\nPOLYNOMIAL 2:";
    p2.display();
    Node *r=new Node();
    head=r;
    Node * p=p1.head;
    Node * q=p2.head;
    while(p && q)
    {
        if(p->exp==q->exp)
        {
            r->coeff=p->coeff+ q->coeff;
            r->exp=p->exp;
            p=p->next;
            q=q->next;
        }
        else
        {
            if(p->exp>q->exp)
            {
                r->coeff=p->coeff;
                r->exp=p->exp;
                p=p->next;
            }
            else
            {
                r->coeff=q->coeff;
                r->exp=q->exp;
                q=q->next;
            }
        }
        if(p!=NULL && q!=NULL)
        {
            r->next=new Node();
            r=r->next;
        }
    }
    while(p|| q)
    {
        if(p|| q)
        {
            r->next=new Node();
            r=r->next;
        }
        if(p)
        {
            r->coeff=p->coeff;
            r->exp=p->exp;
            p=p->next;
        }
        if(q)
        {
            r->coeff=q->coeff;
            r->exp=q->exp;
            q=q->next;
        }
    }
sortPower();
removeDuplicate();
    cout<<"\nADDITION OF 2 POLYNOMIALS:";
    display();
}
int main()
{
    polynomial p1,p2,p3,p4;
    cout<<"1.SET FIRST POLYNOMIAL\n2.SET SECOND POLYNOMIAL\n3.DISPLAY TWO POLYNOMIALS\n4.ADD TWO POLYNOMIALS\n5.MULTIPLICATION TWO POLYNOMIALS\n0.EXIT";
    int option;
   do
   {
       cout<<"\n---------------------------------------------------------------------------------------------------"<<endl;
       cout<<"ENTER YOUR OPTION:";
       cin>>option;
       cout<<"---------------------------------------------------------------------------------------------------"<<endl;
       switch(option)
       {
       case 0:
           cout<<"EXITING.........";
           break;
       case 1:
           p1.createNode();
           break;
       case 2:
           p2.createNode();
           break;
       case 3:
           {
               cout<<"POLYNOMIAL 1:";
               p1.display();
               cout<<"\nPOLYNOMIAL 2:";
               p2.display();
               cout<<"\n";
               break;
           }
       case 4:
           {
               p3.add(p1,p2);
               cout<<endl;
               break;
           }
       case 5:
            {
                p4.multiply(p1,p2);
                cout<<endl;
                break;
            }
       default:
           cout<<"INVALID OPTION,TRY AGAIN!\n";
           break;
       }

   }while(option);
   return 0;
}
