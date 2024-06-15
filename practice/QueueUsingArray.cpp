#include<bits/stdc++.h>
using namespace std;

struct Queue{
  int front;
  int rear;
  int size;
  int *ele;
};

void enqueue(Queue *q,int val){
  if(q->rear<q->size-1){
    q->rear++;
    q->ele[q->rear] = val;
  }
  else{
    cout<<"Queue is full";
  }
}

int dequeue(Queue *q){
  int x;
  if(q->rear == q->front){
    cout<<"Queue is empty";
  }
  else{
    q->front++;
    x = q->ele[q->front];
    q->ele[q->front] = -1;
  }
  return x;
}

void Display(Queue *q){
  for(int i = q->front+1 ; i <= q->rear ; i++){
    cout<<q->ele[i]<<endl;
  }
}

int main(){
  Queue *q = new Queue;
  q->size = 5;
  q->front = q->rear = -1;
  q->ele = new int[q->size];
  enqueue(q,0);
  enqueue(q,10);
  enqueue(q,100);
  enqueue(q,1000);
  Display(q);
  dequeue(q);
  Display(q);
  return 0;
}
