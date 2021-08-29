#include<iostream>
using namespace std;
class queue
{
   int *arr;
   int front;
   int s;
   int rear;
   int capacity;
  public:
    queue(int s)
    {
      arr=new int[s];
      this->s=s;
      capacity=0;
      front=rear=-1;
    }
    ~queue()
    {
      delete [] arr;
    }
    void enqueue(int);
    void dequeue();
    bool isEmpty();
    bool isFull();
    int queueFront();
    int size();
    void display();
};
bool queue::isFull()
{
  return (rear+1)%s==front;
}
bool queue::isEmpty()
{
  return rear==front;
}
void queue::enqueue(int x) {
  if(isFull())
    cout<<"QUEUE OVERFLOW"<<endl;
  else
  {
    if(front==-1)front=0;
    cout<<"INSERTING ELEMENT:"<<x<<endl;
    rear=(rear+1)%s;
    arr[rear]=x;
    capacity++;
  }
}
int queue::queueFront()
{
  if(isEmpty())
  {
    cout<<"QUEUE IS EMPTY"<<endl;
    return -1;
  }
  else
    return arr[front];
}
void queue::dequeue()
{
  if(isEmpty())
    cout<<"QUEUE UNDERFLOW"<<endl;
  else
  {
    capacity--;
    cout<<"REMOVING ELEMENT:"<<queueFront()<<endl;
    if(front==rear)
      front=rear=-1;
    else
     front=(front+1)%s;
  }
}
int queue::size()
{
  return capacity;
}
void queue::display()
{
  if(isEmpty())
    cout<<"QUEUE IS EMPTY"<<endl;
  else
  {
    if (rear >= front)
       for (int i = front; i <= rear; i++)
            printf("%d ",arr[i]);
    else
    {
      for (int i = front; i < s; i++)
            printf("%d ", arr[i]);
      for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
      cout<<endl;
      }
    }
}
int main()
{
  int choice,n;
  cout<<"------------------------QUEUE OPERATION USING ARRAY-------------------------"<<endl;
  cout<<"1.ENQUEUE\n2.DEQUEUE\n3.FRONT ELEMENT\n4.SIZE OF THE QUEUE\n5.DISPLAY\n0.EXIT\n";
  cout<<"----------------------------------------------------------------------------"<<endl;
  cout<<"ENTER THE NO OF THE ELEMENTS:";
  cin>>n;
  queue s(n);
  do{
    cout<<"\n------------------------------------------------------------------------"<<endl;
    cout<<"ENTER YOUR OPTION:";
    cin>>choice;
    switch (choice) {
      case 0:
        cout<<"EXITING.....";
        break;
      case 1:
      {
        int value;
        cout<<"ENTER THE ELEMENT:";
        cin>>value;
        s.enqueue(value);
        break;
      }
      case 2:
        s.dequeue();
        break;
      case 3:
        cout<<"QUEUE FRONT ELEMENT:"<<s.queueFront()<<endl;
        break;
      case 4:
        cout<<"NO OF ELEMENTS IN A QUEUE:"<<s.size()<<endl;
        break;
      case 5:
      {
        cout<<"ELEMENTS STORED IN A QUEUE:";
        s.display();
        break;
      }
      default:
      cout<<"INVALID OPTION, TRY AGAIN!"<<endl;
    }
  }
    while(choice!=0);
    return 0;
  }
