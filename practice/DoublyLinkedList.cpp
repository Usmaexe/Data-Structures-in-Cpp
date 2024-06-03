#include <bits/stdc++.h>
using namespace std;

struct Node{
  struct Node *prev;
  struct Node *next;
  int data;
}*first,*before,*current;


//FUNCTION TO CREATE A LINKED LIST
void create(int A[], int n){
  before->prev = first;
  before->data = A[0];
  first->next=before;

  for(int i = 1 ; i < n ; i++){
    current = new Node;
    current->data = A[i];
    current->prev = before;
    before->next = current;
    current->next = nullptr;
    before = current;
    
  }
}

void display(){
  current = first;
  while(current!=NULL){
    cout<<current->data<<endl;
    current=current->next;
  }
}

void insert(int t,int x){
  current = new Node;
  current->data = x;
  if(t==0){
    current->prev = nullptr;
    current->next = first;
    first->prev = current;
    first = current;
  }
  else{
    before = first;
    // Node *next = new Node;
    for(int i = 1 ; i < t ; i++){
      before = before->next;
    }
    current->next = before->next;
    if(before->next!=nullptr){
      (before->next)->prev = current;
    }
    current->prev = before;
    before->next = current;
  }
}

int length(){
  int n = 0;current = first;
  while(current!=NULL){
    current=current->next;
    n++;
  }
  return n;
}

void Delete(int t){
  if(t==0){
    current = first;
    first = first->next;
    if(first!=nullptr){
      first->prev = nullptr;
    }
    delete current;
  }
  else{
    before = first;
    current = first->next;
    for(int i = 1 ; i < t ; i++){
      before = before->next;
      current = current->next;
    }
    before->next = current->next;
    if(current->next)
      current->next->prev = before;
    delete current;
  }
}

void Reverse(){
  current = first; 
  Node *temp;
  while(current!=nullptr){
    temp = current->next;
    current->next = current->prev;
    current->prev = temp;
    current = current->prev;

    if(current->next==nullptr){
      current->next = current->prev;
      current->prev = nullptr;
      first = current;
      break;
    }
  }

}

int main(){
  int n = 4,A[4] = {3,4,5,9};

  first = new Node;
  first->prev = nullptr;
  first->next = nullptr;
  first->data = 5;
  // cout<<first->data;

  current  = new Node;
  before  = new Node;
  create(A,n);
  display();
  int t,x; 
  cout<< "Position to insert at : ";
  cin>>t;
  cout<< "ELement : ";
  cin>>x;
  if(t<=length()){insert(t,x);}
  display();
  cout<< "The length of the linked list : " <<  length() << endl;
  
  cout<< "Position to delete at (0 indexed): ";
  cin>>t;
  if(t>=0&&t<length()){Delete(t);}
  display();
  Reverse();
  cout<<"reversed list :"<<endl;
  display();
  return 0;
}