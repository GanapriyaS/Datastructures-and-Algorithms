#include <iostream>
using namespace std;
class HashMapTable{
   private:
      int *hash;
      bool*flag;
      int size;
    public:
   HashMapTable() {
     cout<<"ENTER THE SIZE OF THE HASH TABLE:";
     cin>>size;
      hash = new int[size];
      flag=new bool[size];
      for (int i = 0; i < size; i++)
         flag[i]=true;
   }
   int HashFunc(int k) {
      return k % size;
   }
   int probe(int k)
     {
       int index=HashFunc(k);
       int i=0;
       while(flag[(index+i)%size]!=true)
       {
         i++;
         if(i>=size)
         return -1;
       }
       return (index+i)%size;
     }
     void insertion(int k) {
        int index=HashFunc(k);
        if(flag[index]!=true )
         index=probe(k);
        if(index==-1)
        {
          cout<<"FULL MEMORY!!!!\n";
          return;
        }
        hash[index]=k;
        flag[index]=false;
     }
     int search(int k) {
        int index=HashFunc(k);
        int i=0;
        while(hash[(index+i)%size]!=k && flag[(index+i)%size]==false)
        {
           i++;
          if(i>=size)
          return -1;
        }
        if(flag[(index+i)%size]==true)
        return -1;
        if(hash[(index+i)%size]==k)
        return (index+i)%size;
     }
     void deletion(int k) {
         int index=search(k);
         if(index==-1)
         {
           cout<<"ELEMENT NOT FOUND\n";
           return;
         }
         flag[index]=true;
         cout<<"ELEMENT "<<k<<" DELETED AT LOCATION "<<index<<endl;
      }
      void display()
      {
        int i=0;
        for(;i<size;i++)
        {
          if(flag[i]==false)
            cout<<hash[i]<<" ";
          else
            cout<<"-"<<" ";
        }
        cout<<endl;
      }
   ~HashMapTable() {
        delete[] hash;
        delete[] flag;
     }
};
int main() {
  cout<<"------------------------------------------------------------\n";
   HashMapTable hashmap;
   int v;
   int c;
   cout<<"1.INSERTION"<<endl;
   cout<<"2.SEARCH AN ELEMENT"<<endl;
   cout<<"3.DELETION"<<endl;
   cout<<"4.ORDER OF ELEMENTS IN A HASHTABLE"<<endl;
   cout<<"5.EXIT"<<endl;
   cout<<"-----------------------------------------------------------\n";
   while(1) {
      cout<<"\nENTER YOUR CHOICE:";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"ENTER THE ELEMENT TO BE INSERTED: ";
            cin>>v;
            hashmap.insertion(v);
         break;
         case 2:
            cout<<"ENTER THE ELEMENT TO BE SEARCH: ";
            cin>>v;
            int loc;
            loc=hashmap.search(v) ;
            if(loc!= -1)
               cout<<"ELEMENT FOUND AT LOCATION "<<loc<<endl;
            else
               cout<<"ELEMENT NOT FOUND\n";
         break;
         case 3:
            cout<<"ENTER THE ELEMENT TO BE DELETED: ";
            cin>>v;
            hashmap.deletion(v);
         break;
         case 4:
            cout<<"ORDER OF ELEMENTS IN A HASHTABLE:\n";
            hashmap.display();
         break;
         case 5:
            cout<<"EXITING................";
            exit(1);
         default:
            cout<<"ENTER THE VALID OPTION\n";
      }
   }
   return 0;
}
