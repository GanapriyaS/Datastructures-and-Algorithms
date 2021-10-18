#include <iostream>
using namespace std;
class HashMapTable{
   private:
      int *hash;
      bool*flag;
      int size;
      int curr_size;
      int R;
   public:
      HashMapTable() {
        curr_size=0;
        cout<<"ENTER THE SIZE OF THE HASH TABLE:";
        cin>>size;
        cout<<"ENTER THE VALUE OF R (PRIME NOS ONLY):";
        cin>>R;
         hash = new int[size];
         flag=new bool[size];
         for (int i = 0; i < size; i++)
            flag[i]=true;
      }
      int HashFunc1(int k) {
         return k % size;
      }
      int HashFunc2(int k) {
         return R-(k%R);
      }
      int probe(int k)
      {
        int index1=HashFunc1(k);
        int i=0;
        int index2=HashFunc2(k);
        while(flag[(index1+i* index2)%size]!=true)
        {
          i++;
          if(i>=size)
          return -1;
        }
        return (index1+i* index2)%size;
      }
      void insertion(int k)
      {
        if (curr_size==size)
        {
          cout<<"FULL MEMORY!!!!\n";
          return;
        }
         int index=HashFunc1(k);
         if(flag[index]!=true )
          index=probe(k);
          if(index==-1)
          {
            cout<<"INSERATION FAILED!!!!\n";
            return;
          }
         hash[index]=k;
         flag[index]=false;
         curr_size++;
      }
      int search(int k) {
         int index1=HashFunc1(k);
         int index2=HashFunc2(k);
         int i=0;
         while(hash[(index1 +i*index2)%size]!=k && flag[(index1 +i* index2)%size]==false)
         {
            i++;
           if(i>=size)
           return -1;
         }
         if(flag[(index1 +i*index2)%size]==true)
         return -1;
         if(hash[(index1 +i*index2)%size]==k)
         return (index1 +i*index2)%size;
      }
      void deletion(int k) {
         int index=search(k);
         if(index==-1)
         {
           cout<<"ELEMENT NOT FOUND\n";
           return;
         }
         flag[index]=true;
        curr_size--;
         cout<<"ELEMENT "<<k<<" DELETED AT LOCATION "<<index<<endl;
      }
      void rehash()
      {
          curr_size=0;
          cout<<"ENTER THE SIZE OF THE ARRAY:";
          cin>>size;
          bool *temp_flag=new bool[size];
          int *hashtable=new int[size];
          hash=hashtable;
          delete[] hashtable;
          flag=temp_flag;
          delete[] temp_flag;
          for (int i = 0; i < size; i++)
             flag[i]=true;
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
   cout<<"4.REHASHING"<<endl;
   cout<<"5.ORDER OF ELEMENTS IN A HASHTABLE"<<endl;
   cout<<"6.EXIT"<<endl;
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
              cout<<"REHASHING\n";
              hashmap.rehash();
         break;
         case 5:
            cout<<"ORDER OF ELEMENTS IN A HASHTABLE:\n";
            hashmap.display();
         break;
         case 6:
            cout<<"EXITING................";
            exit(1);
         default:
            cout<<"ENTER THE VALID OPTION\n";
      }
    }
   return 0;
}
