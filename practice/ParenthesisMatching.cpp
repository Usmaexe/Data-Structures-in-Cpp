#include <bits/stdc++.h>
using namespace std;
struct Node{
  char data;
  Node *next;
};
class Stack{
  private :
    Node *head;
  public :
    Stack();
    void push(char data);
    void display();
    int pop();
    ~Stack();
};


Stack::Stack(){
  this->head = nullptr;
}
void Stack::push(char data){
  Node *current = new Node;
  current->data = data;
  current->next = this->head;
  this->head = current;
}
void Stack::display(){
  Node *current = this->head;
  while(current!=NULL){
    cout << current->data << " -> ";
    current = current->next;
  }
  cout << endl;
}
int Stack::pop(){
  char x;
  if(this->head){
    x=this->head->data;
    Node *current = new Node;
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
Stack::~Stack(){
  delete []head;
}
int main(){
  string exp = "((A*B)+(C+D))";
  Stack st;
  int i;
  for(i = 0 ; i < (int)exp.length() ; i++){
    if(exp[i]=='('||exp[i]=='['||exp[i]=='{'){
      st.push(exp[i]);
    }
    if(exp[i]==')'){
      if('('!=st.pop()){
        cout<<"Expression is wrong";
        break;
      }
    }
    else if(exp[i]=='}'){
      if('{'!=st.pop()){
        cout<<"Expression is wrong";
        break;
      }
    }
    else if(exp[i]==']'){
      if('['!=st.pop()){
        cout<<"Expression is wrong";
        break;
      } 
    }
  }
  if(i == (int)exp.length())
    cout<<"Expression valid"<<endl;

  return 0;
}