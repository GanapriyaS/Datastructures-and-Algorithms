// https://leetcode.com/problems/design-linked-list/

class Node{
    public:
    int data;
    Node* next;
};
    
class MyLinkedList {
    
public:
    Node *first;
    MyLinkedList() {
        first=NULL;
    }
    
    int get(int index) {
        Node*temp=first;
        int len=length();
        if(0<=index && index<len){
            for(int i=0;i<index;i++){
                temp=temp->next;
            }
            return temp->data;
        }
        else
            return -1;
    }
    
    void addAtHead(int val) {
        Node*temp=new Node();
        temp->data=val;
        temp->next=first;
        first=temp;  
    }
    
    int length(){
        Node*temp=first;
        int len=0;
        while(temp){
            temp=temp->next;
            len++;
        }
        return len;
    }
    
    void addAtTail(int val) {
        
        Node*temp=new Node();
        temp->data=val;
        temp->next=NULL;
        if(first==NULL){
            first=temp;
        }
        else
        {
            Node*flag=first;
            while(flag && flag->next!=NULL){
                flag=flag->next;
            }
            flag->next=temp;
        }
    }
    
    void addAtIndex(int index, int val) {
        int len=length();
        if(0<=index && index<=len){
        Node*flag=first;
        
        Node*temp=new Node();
        temp->data=val;
        temp->next=NULL;
            if(index==0){
                addAtHead(val);
            }else{
        for(int i=0;i<index-1;i++){
            flag=flag->next;
        }
        temp->next=flag->next;
        flag->next=temp;
        }
        }
    }
    
    void deleteAtIndex(int index) {
        Node*p,*q=NULL;
        int len=length();
         if(0<=index && index<len){
             if(index==0)
             {
                 p=first;
                 first=first->next;
                 delete p;
             }
             else{
                 p=first;
                 for(int i=0;i<index;i++){
                     q=p;
                    p=p->next;   
                }   
                 q->next=p->next;       
                 delete p;
             }
         }
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
