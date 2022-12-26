#include <iostream>
using namespace std;

void find(int arr[],int n){
    int key;
    bool flag;
    cout<<"Enter key element to search :";
    cin>>key;
    for(int i=0;i<n;i++){
        if(arr[i]==key)
        {
            flag=1;
            break;
        }
    }
    cout<<"Is element "<<key<<" present in an array : ";
    cout<< (flag?"YES\n":"NO\n");
}