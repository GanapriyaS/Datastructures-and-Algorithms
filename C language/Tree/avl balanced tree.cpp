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
    Node(int data)
    {
        lchild=rchild=NULL;
        this->data=data;
    }
};
class Tree
{
public:
    Node *root;
    Tree(){root=NULL;}
    ~Tree(){delete root;}
    Node* insertion(Node*,int);
    Node* rr_rotation(Node *);
    Node* ll_rotation(Node *);
    Node* lr_rotation(Node *);
    Node* rl_rotation(Node *);
    Node * deletion(Node *,int);
    void search(int);
    Node * InPre(Node *);
    Node * InSuc(Node *);
    void postorder(Node *);
    void inorder(Node *);
    void preorder(Node *);
    int height(Node * );
    int bfactor(Node *);
    void display(Node *,int);
    void levelOrder(Node *);
};
Node *Tree:: InPre(Node * p)
{
    while(p && p->rchild)
        p=p->rchild;
    return p;
}
Node * Tree::InSuc(Node * p)
{
    while(p && p->lchild)
        p=p->lchild;
    return p;
}
int Tree:: height(Node * p)
{
    int x,y;
    if(p==NULL)return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    return x>y?x+1:y+1;
}
int Tree::bfactor(Node * p)
{
    int lh = height (p->lchild);
    int rh = height (p->rchild);
    return lh - rh;
}
Node* Tree::rr_rotation(Node *p)
{
    Node *temp = p->rchild;
    p->rchild = temp->lchild;
    temp->lchild = p;
    if(p==root)
        root=temp;
    return temp;
}
Node* Tree::ll_rotation(Node *p)
{
    Node* temp = p->lchild;
    p->lchild = temp->rchild;
    if(p==root)
        root=temp;
    temp->rchild = p;

    return temp;
}
Node* Tree::lr_rotation(Node *p)
{
    Node * temp = p->lchild;
    p->lchild=rr_rotation (temp);
    return ll_rotation (p);
}
Node* Tree::rl_rotation(Node *p)
{
    Node * temp = p->rchild;
    p->rchild=ll_rotation (temp);
    return rr_rotation (p);
}
Node * Tree::insertion(Node *p, int value)
{
    if (root == NULL)
    {
        root = new Node(value);
        return root;
    }
    if(!p)
        return  new Node(value);
    if (value < p->data)
        p->lchild = insertion(p->lchild, value);
    else if (value >p->data)
        p->rchild = insertion(p->rchild, value);
    else
        {
            cout<<"ELEMENT ALREADY PRESENT!"<<endl;
            return p;
        }
    if(bfactor(p)==2 && bfactor(p->lchild)==1)
        return ll_rotation(p);
    if(bfactor(p)==2 && bfactor(p->lchild)==-1)
        return lr_rotation(p);
    if(bfactor(p)==-2 && bfactor(p->rchild)==-1)
        return rr_rotation(p);
    if(bfactor(p)==-2 && bfactor(p->rchild)==1)
        return rl_rotation(p);
    return p;
}
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
Node* Tree::deletion(Node * p,int key)
{
   if (!root)
   {
      cout<<"TREE IS EMPTY!"<<endl;
      return NULL;
   }
   Node *q=NULL;
   int x;
   if(!p)return NULL;
   if(!p->lchild && !p->rchild)
   {
       if(p->data==key)
       {
            if(p==root)
                root=NULL;
            delete p;
            return NULL;
       }
       return NULL;
   }
   if(key < p->data)
        p->lchild=deletion(p->lchild,key);
    else if(key > p->data)
        p->rchild=deletion(p->rchild,key);
    else
    {
        if(height(p->lchild)>height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=deletion(p->lchild,q->data);
        }
        else
        {
            q=InSuc(p->rchild);
            p->data=q->data;
            p->rchild=deletion(p->rchild,q->data);
        }
    }
        if(bfactor(p)>1 && bfactor(p->lchild)>=0)
        {
            cout<<p->data;
            return ll_rotation(p);
        }
        if(bfactor(p)>1 && bfactor(p->lchild)<0)
        {   cout<<p->data;
            return lr_rotation(p);
        }
        if(bfactor(p)<-1 && bfactor(p->rchild)<=0)
        {   cout<<p->data;
            return rr_rotation(p);
        }
        if(bfactor(p)<-1 && bfactor(p->rchild)>0)
        {   cout<<p->data;
            return rl_rotation(p);
        }
    return p;
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
void Tree::display(Node *p, int level)
{
    if(!root)
{
    cout<<"TREE IS EMPTY!"<<endl;
    return;
}
    int i;
    if (p!=NULL)
    {
        display(p->rchild, level + 1);
        cout<<endl;
        if (p == root)
        cout<<"Root -> ";
        for (i = 0; i < level && p != root; i++)
            cout<<"        ";
        cout<<p->data;
        display(p->lchild, level + 1);
    }
}
int main()
{
    cout<<"---------------------------------------------------------------------------------------------------"<<endl;
    cout<<"1.INSERTION\n2.DELETION\n3.SEARCH AN ELEMENT\n4.HEIGHT OF THE BINARY TREE\n5.PREORDER TRAVERSAL\n6.INORDER TRAVERSAL\n7.POSTORDER TRAVERSAL\n8.LEVELORDER TRAVERSAL\n9.DISPLAY TREE\n0.EXIT";
    Tree avl;
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
                int key;
                cout<<"ENTER THE ELEMENT TO BE INSERTED:";
                cin>>key;
                avl.insertion(avl.root,key);
                cout<<"INSERTING ELEMENT:"<<key<<endl;
                break;
            }
        case 2:
            {
                Node *t=new Node();
                int key;
                cout<<"ENTER THE ELEMENT TO BE DELETED:";
                cin>>key;
                t=avl.deletion(avl.root,key);
                if(t)
                cout<<"DELETING ELEMENT:"<<key<<endl;
                break;
            }
        case 3:
            {
                int key;
                cout<<"ENTER THE ELEMENT TO BE SEARCH:";
                cin>>key;
                avl.search(key);
                break;
            }
        case 4:
            {
                cout<<"HEIGHT OF THE TREE:"<<avl.height(avl.root)<<endl;
                break;
            }
        case 5:
            {
                cout<<"PREORDER TRAVERSAL:";
                avl.preorder(avl.root);
                cout<<endl;
                break;
            }
            case 6:
            {
                cout<<"INORDER TRAVERSAL:";
                avl.inorder(avl.root);
                cout<<endl;
                break;
            }
            case 7:
            {
                cout<<"POSTORDER TRAVERSAL:";
                avl.postorder(avl.root);
                cout<<endl;
                break;
            }
            case 8:
            {
                cout<<"LEVELORDER TRAVERSAL:";
                avl.levelOrder(avl.root);
                cout<<endl;
                break;
            }
            case 9:
            {
                cout<<"BALANCED AVL TREE:";
                avl.display(avl.root,1);
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
