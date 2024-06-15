#include <bits/stdc++.h>
using namespace std;

struct Node{
  int val;
  Node *next;
};
class Queue{
  private :
    Node *front;
    Node *rear;
  public :
    Queue();
    void enqueue(int val);
    int dequeue();
    void display();
    ~Queue();
};
Queue::Queue(){
  front = nullptr;
  rear = nullptr;
}

void Queue::enqueue(int val){
  Node *ele = new Node;
  if(ele==nullptr){//memory can't be allocated  
    cout<<"Queue is full";
  }
  else{
    ele->val = val;
    ele->next=nullptr;
    if(this->front==nullptr){
      this->front = this->rear = ele;
    }
    else{
      this->rear->next = ele;
      this->rear = ele;
    }
  }
}

int Queue::dequeue(){
  int x = -1;
  if(front==nullptr){
    cout<<"Queue is Empty";
  }
  else{
    x = front->val;
    front = front->next;
  }
  return x;
}

void Queue::display(){
  Node *surfing = front;
  while(surfing){
    cout<<surfing->val<<endl;
    surfing = surfing->next;
  }
}

Queue::~Queue(){
  delete[] front;
  delete[] rear;
}

int main(){
  Queue *q = new Queue();
  q->enqueue(3);
  q->enqueue(2);
  q->enqueue(10);
  q->display();
  cout<<q->dequeue();
  cout<<q->dequeue();
  cout<<q->dequeue();
  q->display();

  return 0;
}