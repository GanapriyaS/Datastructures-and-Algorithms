#include<iostream>
#include<queue>
using namespace std;
class Node
{
public:
    Node *lchild;
    int data;
        Node *rchild;
        Node()
        {
            lchild=rchild=NULL;
            data=0;
        }
};
class Tree
{
public:
    Node *root;
    Tree(){root=NULL;}
    ~Tree(){delete root;}
    void insertion(Node*);
    Node * deletion(int);
    void search(int);
    void postorder(Node *);
    void inorder(Node *);
    void preorder(Node *);
    int height(Node * );
    void levelOrder(Node *);
};
void Tree::search(int key)
{
    int depth=0;
    Node*p= root;
    if(!root)
    {
        cout<<"TREE IS EMPTY!"<<endl;
        return;
    }
    while(p)
    {
        depth++;
        if(key==p->data)
        {
            cout<<"ELEMENT "<<p->data<<" FOUND AT DEPTH:"<<depth<<endl;
            return ;
        }

        else if(key<p->data)
            p=p->lchild;
        else
            p=p->rchild;
    }
    cout<<"ELEMENT NOT FOUND!"<<endl;
}
void Tree::insertion(Node* p)
{
   if (root == NULL)
   {
      root=p;
      cout<<"INSERTING ELEMENT:"<<p->data<<endl;
      return;
   }
   Node *t=root;
   Node *r;
   while(t)
   {
       r=t;
       if(p->data<t->data)
            t=t->lchild;
       else if(p->data>t->data)
            t=t->rchild;
       else
       {
           cout<<"ELEMENT ALREADY PRESENT!"<<endl;
           return;
       }
   }
   if(p->data < r->data)
        r->lchild=p;
   else
        r->rchild=p;
   cout<<"INSERTING ELEMENT:"<<p->data<<endl;
}
Node* Tree::deletion(int key)
{
   if (!root)
   {
      cout<<"TREE IS EMPTY!"<<endl;
      return NULL;
   }
   Node * t=root;
   Node * r=NULL;
   while(t)
   {
       if(key==t->data)
            break;
        r=t;
       if(key<t->data)
            t=t->lchild;
       else if(key>t->data)
            t=t->rchild;
   }
    if(!t)
    {
        cout<<"ELEMENT NOT PRESENT!"<<endl;
        return NULL;
    }
    if(!t->lchild && !t->rchild || !t->lchild && t->rchild || t->lchild && !t->rchild )
    {
        Node * child=NULL;
        if(!r)
             root=NULL;
        if(!t->lchild && !t->rchild)
            child=NULL;
        else if(t->lchild)
            child= t->lchild;
        else if( t->rchild)
            child= t->rchild;
        if(r)
        {
            if(r->lchild==t)r->lchild =child;
            else r->rchild=child;
        }
        else
            root = child;
        return t;
    }
    else if(t->rchild && t->lchild)
    {
    Node * suc=t->rchild;
    Node * st=t;

   while (suc->lchild)
   {
      st = suc;
      suc = suc->lchild;
   }
    Node * child=NULL;
        if(!st)
             root=NULL;
        if(!suc->lchild && !suc->rchild)
            child=NULL;
        else  if(suc->lchild)
            child= suc->lchild;
        else if( suc->rchild)
            child= suc->rchild;
        if(st)
        {
            if(st->lchild==suc)st->lchild =child;
            else st->rchild=child;
        }
        else
            root = child;
   if (!r)
   {
      root = suc;
   }
   else
   {
      if (t == r->lchild)
         r->lchild = suc;
      else
         r->rchild= suc;
   }
   suc->lchild = t->lchild;
   suc->rchild = t->rchild;

   return t;
 }
}
int Tree:: height(Node * p)
{
    int x,y;
    if(p==NULL)return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    return x>y?x+1:y+1;
}
void Tree::preorder(Node * p)
{
if(!root)
{
    cout<<"TREE IS EMPTY!"<<endl;
    return;
}
if(p)
{
    cout<<p->data<<" ";
    preorder(p->lchild);
    preorder(p->rchild);
}
}
void Tree::inorder(Node * p)
{
if(!root)
{
    cout<<"TREE IS EMPTY!"<<endl;
    return;
}
if(p)
{
    inorder(p->lchild);
    cout<<p->data<<" ";
    inorder(p->rchild);
}
}
void Tree::postorder(Node * p)
{
if(!root)
{
    cout<<"TREE IS EMPTY!"<<endl;
    return;
}
if(p)
{
    postorder(p->lchild);
    postorder(p->rchild);
    cout<<p->data<<" ";
}
}
void Tree::levelOrder(Node * root)
{
    if(!root)
{
    cout<<"TREE IS EMPTY!"<<endl;
    return;
}
   queue <Node*> q;
   q.push(root);
   while(!q.empty()){
      root = q.front();
      cout << root->data<< " ";
      if(root->lchild != NULL)
         q.push(root->lchild);
      if(root->rchild != NULL)
         q.push(root->rchild);
      q.pop();
   }
}
int main()
{
    cout<<"---------------------------------------------------------------------------------------------------"<<endl;
    cout<<"1.INSERTION\n2.DELETION\n3.SEARCH AN ELEMENT\n4.HEIGHT OF THE BINARY TREE\n5.PREORDER TRAVERSAL\n6.INORDER TRAVERSAL\n7.POSTORDER TRAVERSAL\n8.LEVELORDER TRAVERSAL\n0.EXIT";
    Tree bst;
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
            {
                Node *t=new Node();
                cout<<"ENTER THE ELEMENT TO BE INSERTED:";
                cin>>t->data;
                bst.insertion(t);
                break;
            }
        case 2:
            {
                Node *t=new Node();
                int key;
                cout<<"ENTER THE ELEMENT TO BE DELETED:";
                cin>>key;
                t=bst.deletion(key);
                if(t)
                cout<<"DELETING ELEMENT:"<<t->data;
                break;
            }
        case 3:
            {
                int key;
                cout<<"ENTER THE ELEMENT TO BE SEARCH:";
                cin>>key;
                bst.search(key);
                break;
            }
        case 4:
            {
                cout<<"HEIGHT OF THE TREE:"<<bst.height(bst.root)<<endl;
                break;
            }
        case 5:
            {
                cout<<"PREORDER TRAVERSAL:";
                bst.preorder(bst.root);
                cout<<endl;
                break;
            }
            case 6:
            {
                cout<<"INORDER TRAVERSAL:";
                bst.inorder(bst.root);
                cout<<endl;
                break;
            }
            case 7:
            {
                cout<<"POSTORDER TRAVERSAL:";
                bst.postorder(bst.root);
                cout<<endl;
                break;
            }
            case 8:
            {
                cout<<"LEVELORDER TRAVERSAL:";
                bst.levelOrder(bst.root);
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
