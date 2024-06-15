#include<bits/stdc++.h>
using namespace std;

struct Queue{
  int front;
  int rear;
  int size;
  int *ele;
};

// void create(Queue *q,int size){
// }

void enqueue(Queue *q,int val){
  if((q->rear+1)%q->size!=q->front){
    q->rear = (q->rear+1)%q->size;
    q->ele[q->rear] = val;
  }
  else{
    cout << "Queue is full";
  }
}

int dequeue(Queue *q){
  int x = -1;
  if(q->rear == (q->front+1)%q->size){
    cout << "Queue is empty";
  }
  else{
    q->front = (q->front+1) % q->size;
    x = q->ele[q->front];
  }
  return x;
}

void Display(Queue *q){
  int front = (q->front+1);
  do{
     cout<<q->ele[front]<<endl;
     front = (front+1) % q->size;
  }while(front!=(q->rear+1)%q->size);
}

int main(){
  Queue *q = new Queue;
  
  q->front = 0;
  q->rear = 0;
  q->size = 6;
  q->ele = new int[6];
  enqueue(q,9);
  enqueue(q,18);
  enqueue(q,27);
  enqueue(q,37);
  enqueue(q,47);
  Display(q);
  dequeue(q);
  dequeue(q);
  Display(q);
  enqueue(q,100);
  enqueue(q,300);
  Display(q);
  return 0;
}
