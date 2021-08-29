#include <iostream>
#include <queue>
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
      Node * root;
      Tree(){root=NULL;}
      ~Tree(){delete root;}
      void createNode();
      void insertion(Node*);
      Node* deletion(int);
      void postorder(Node *);
      void inorder(Node *);
      void preorder(Node *);
      int height(Node * );
      void levelOrder(Node *);
};
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
int Tree:: height(Node * p)
{
    int x,y;
    if(p==NULL)return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    return x>y?x+1:y+1;
}
void Tree::createNode()
{
    queue <Node*> q;
    Node *p,*t;
    int x;
    cout<<"ENTER ROOT VALUE:";
    cin>>x;
    root=new Node(x);
    if(!root)
            {
                cout<<"MEMORY ERROR!";
                return;
            }
    q.push(root);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        cout<<"ENTER LEFT CHILD OF "<<p->data<<" :";
        cin>>x;
        if(x!=-1)
        {
            t=new Node(x);
            if(!t)
            {
                cout<<"MEMORY ERROR!";
                return;
            }
            p->lchild=t;
            q.push(t);
        }
        cout<<"ENTER RIGHT CHILD OF "<<p->data<<" :";
        cin>>x;
        if(x!=-1)
        {
            t=new Node(x);
            if(!t)
            {
                cout<<"MEMORY ERROR!";
                return;
            }
            p->rchild=t;
            q.push(t);
        }
    }
}
void Tree::insertion(Node* p)
{
    Node * t=NULL;
    if (root == NULL)
    {
        root=p;
        return;
    }

    queue <Node*> q;
   q.push(root);
   while(!q.empty())
   {
      t = q.front();
      if(t->lchild)
         q.push(t->lchild);
      else
      {
          t->lchild=p;
          return ;
      }
      if(t->rchild)
         q.push(t->rchild);
      else
      {
          t->rchild=p;
          return;
      }
      q.pop();
   }
}
Node* Tree::deletion(int key)
{
    int x;
	if (root == NULL)
    {
        cout<<"TREE IS EMPTY!"<<endl;
        return NULL;
    }
    if(!root->lchild && !root->rchild)
    {
        if(root->data==key)
        {
            x=root->data;
            root=NULL;
            return new Node(x);
        }
        cout<<"ELEMENT NOT FOUND!"<<endl;
        return NULL;
    }
	queue<Node*> q;
	q.push(root);

Node* temp;
Node* t;
	Node* key_node = NULL;
	while (!q.empty()) {

		temp = q.front();
		q.pop();

		if (temp->data == key)
			key_node = temp;

		if (temp->lchild)
        {
           if(!temp->lchild->lchild && !temp->lchild->rchild)
             t=temp;
			q.push(temp->lchild);
        }

		if (temp->rchild)
        {
          if(!temp->rchild->lchild && !temp->rchild->rchild)
             t=temp;
			q.push(temp->rchild);
        }
	}
	if (key_node) {
		x = temp->data;
        temp->data=key_node->data ;
		key_node->data = x;
	}
	else
    {
        cout<<"ELEMENTS NOT FOUND!";
        return NULL;
    }
  if(t->lchild==temp)
    t->lchild=NULL;
  else
    t->rchild=NULL;
  return temp;
}

int main()
{
    cout<<"---------------------------------------------------------------------------------------------------"<<endl;
    cout<<"1.CREATE TREE\n2.INSERTION\n3.DELETION\n4.HEIGHT OF THE TREE\n5.PREORDER TRAVERSAL\n6.INORDER TRAVERSAL\n7.POSTORDER TRAVERSAL\n8.LEVELORDER TRAVERSAL\n0.EXIT";
    Tree bt;
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
                bt.createNode();
                break;
            }
        case 2:
            {
                Node *t=new Node();
                cout<<"ENTER THE ELEMENT TO BE INSERTED:";
                cin>>t->data;
                bt.insertion(t);
                break;
            }
        case 3:
            {
                Node *t=new Node();
                int key;
                cout<<"ENTER THE ELEMENT TO BE DELETED:";
                cin>>key;
                t=bt.deletion(key);
                if(t)
                cout<<"DELETING ELEMENT:"<<t->data<<endl;
                break;
            }
        case 4:
            {
                cout<<"HEIGHT OF THE TREE:"<<bt.height(bt.root)<<endl;
                break;
            }
        case 5:
            {
                cout<<"PREORDER TRAVERSAL:";
                bt.preorder(bt.root);
                cout<<endl;
                break;
            }
            case 6:
            {
                cout<<"INORDER TRAVERSAL:";
                bt.inorder(bt.root);
                cout<<endl;
                break;
            }
            case 7:
            {
                cout<<"POSTORDER TRAVERSAL:";
                bt.postorder(bt.root);
                cout<<endl;
                break;
            }
            case 8:
            {
                cout<<"LEVELORDER TRAVERSAL:";
                bt.levelOrder(bt.root);
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
