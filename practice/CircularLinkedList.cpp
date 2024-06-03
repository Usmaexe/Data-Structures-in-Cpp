#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node *next;
};

class CircularLinkedList{
  private : 
    Node *head;
  public :
    CircularLinkedList(int *A,int n);
    Node *getHead();
    void Display(Node *p);
    void DisplayRecursively(Node *p);
    void Insert(int pos,int value);
    int Delete(int pos);
    ~CircularLinkedList();
};

CircularLinkedList::CircularLinkedList(int *A,int n){
  Node *t;
  Node *tail;
  head = new Node;
  head->data = A[0];
  head->next = head;
  tail = head;
  for(int i = 1 ; i < n ; i++){
    t = new Node;
    t->data = A[i];
    t->next = tail->next;
    tail->next = t;
    tail = t;
  }
}

Node *CircularLinkedList::getHead(){
  return head;
}

void CircularLinkedList::Display(Node *p){
  do{
    cout<< "-->" <<p->data;
    p = p->next;
  }while(p!=head);
  cout<<endl;
}

void CircularLinkedList::DisplayRecursively(Node *p){
  static int flag = 0;
  if(flag==0||p!=head){
    flag = 1;
    cout<< "-->" <<p->data;
    DisplayRecursively(p->next);
  }
  flag = 0;
  cout<<endl;
}
void CircularLinkedList::Insert(int pos,int val){
  Node *t = new Node;
  Node *p=head;
  t->data = val;
  if(pos==1){
    while(p->next!=head){
      p = p->next;
    }
    t->next = head;
    p->next = t;
    head = t;
  }
  else{
    for(int i = 1 ; i < pos - 1 ; i++){
      p = p->next;
    }
    t->next = p->next;
    p->next = t;
  }
  
}

CircularLinkedList::~CircularLinkedList(){
  //We Delete at the head
  Node* p = head;
  while (p->next != head){
      p = p->next;
  }

  while (p != head){
      p->next = head->next;
      delete head;
      head = p->next;
  }

  if (p == head){
      delete head;
      head = nullptr;
  }
}

int CircularLinkedList::Delete(int pos){
  Node *p = head;
  int x;
  if(pos == 1){
    while(p->next!=head){
      p=p->next;
    } 
    x=head->data;
    if(p==head){
      delete head;
      head = nullptr;
    }
    else{
      p->next = head->next;
      delete head;
      head = p->next;
    }
    
  }
  else{
    
    Node *t = head;
    for(int i = 0 ; i < pos-2 ; i++){
      p = p->next;
    }
    t = p->next;
    x = t->data;
    p->next = t->next;
    delete t;
  }
  return x;
}

int main(){
  int A[] = {4,5,10,45};
  CircularLinkedList l(A,4);
  Node *head = l.getHead();
  l.Display(head);
  l.DisplayRecursively(head);
  l.Insert(1,9);
  head = l.getHead();
  l.Display(head);
  cout << l.Delete(1) << endl;
  head=l.getHead();
  l.Display(head);
  return 0;
}