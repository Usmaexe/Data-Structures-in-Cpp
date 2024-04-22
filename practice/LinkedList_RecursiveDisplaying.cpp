#include <iostream>
using namespace std;
class Node{
  public :
    int data;
    Node *next;
};

void recursiveDisplay(Node *p){
  if(p){
    cout << p->data << " -> ";
    recursiveDisplay(p->next);
  }
}
int main(){
  int A[5] = {2,4,6,8,10};
  Node *head = new Node;
  Node *temp;
  Node *last = new Node;
  head->data = A[0];
  head->next = nullptr;

  last = head;
  for(int i = 1 ; i<5 ; i++){
    temp = new Node;
    temp->data = A[i];
    temp->next = nullptr;
    last->next = temp;
    last = temp;
  }
  // Node *p = new Node;
  // p = head;
  // while(p){
  //   cout<<p->data<<" -> ";
  //   p = p->next;
  // }
  recursiveDisplay(head);
  return 0;
}