#include <bits/stdc++.h>
using namespace std;

class Stack{
  private :
    int size;
    int top;//0-indexed
    int *elements;
  public :
    Stack();
    Stack(int size,int top,int *elements);
    void push(int val);
    int pop();
    int peek(int pos);

    int getSize();
    int getTop();
    ~Stack();
};
Stack::Stack(){
  this->size = 0;
  this->top = -1;
}
Stack::Stack(int size,int top,int *elements){
  this->size = size;
  this->top = top;
  this->elements = new int[size];
  for(int i = 0 ; i < size ; i++){
    this->elements[i] = elements[i];
  }
}
void Stack::push(int val){
  if(this->getTop()==this->getSize()-1){
    cout<<"Stack Overflow!!"<<endl;
  }
  else{
    top++;
    elements[top] = val;
  }
}
int Stack::pop(){
  int x;
  if(this->getTop()==-1){
    cout<<"Stack empty";
    return 0;
  }
  else{
    x = elements[this->top] ;
    top--;
    return x;
  }
}

int Stack::peek(int pos){
  if(pos<0||pos>this->getTop()){
    cout<<"position out of bound";
    return -1;
  }
  else{
    return elements[this->getTop()-pos+1];
  }
}

int Stack::getSize(){
  return size;
}
int Stack::getTop(){
  return top;
}

Stack::~Stack(){
  delete []this->elements;
}

int main(){
  int A[6] = {3,33,333,3333};
  Stack first(6,3,A);
  cout<<first.getTop()<<endl;
  cout<<first.peek(2);//1-indexed
  return 0;
}