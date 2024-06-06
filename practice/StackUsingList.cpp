#include <bits/stdc++.h>
using namespace std;

struct node{
  int val;
  node *next;
};

class Stack{
  private :
    node *head;
  public :
    Stack();
    void push(int val);
    void display();
    int pop();
    bool isEmpty();
    int getSize();
    int getTop();
    int peek(int index);
    ~Stack();
};

Stack::Stack(){
  this->head = nullptr;
}
void Stack::push(int val){
  node *current = new node;
  current->val = val;
  current->next = this->head;
  this->head = current;
}
void Stack::display(){
  node *current = this->head;
  while(current!=NULL){
    cout << current->val << " -> ";
    current = current->next;
  }
  cout << endl;
}
int Stack::pop(){
  int x;
  if(this->head){
    x=this->head->val;
    node *current = new node;
    current = this->head;
    this->head = this->head->next;
    delete []current;
    return x;
  }
  else{
    cout << "Stack is empty";
    return -1;
  }
}
int Stack::getSize(){
  int size = 0;
  node *current = this->head;
  while(current!=NULL){
    current = current->next;
    size++;
  }
  return size;
}
int Stack::getTop(){
  if(this->head){
    return this->head->val;
  }
  else{
    return -1;
  }
}
bool Stack::isEmpty(){
  if(!this->head)
    return true;
  else return false;
}
int Stack::peek(int val){
  if(!this->isEmpty()){
    node *current = this->head;
    for(int i = 1 ; i < val ; i++){
      current = current->next;
      if(!current){
        break;
      }
    }
    if(current)
      return current->val;
    else
    {
      cout<<"Index out of range";
      return -1;
    }
  }
  cout<<"Stack Empty"<<endl;
  return -1;
}
Stack::~Stack(){
  delete []head;
}

int main(){
  //Linked List :
  Stack st;
  st.push(2);
  st.push(4);
  st.push(6);
  st.display();
  cout<<st.peek(1)<<endl;
  cout<<st.peek(3)<<endl;
  st.display();
  return 0;
}