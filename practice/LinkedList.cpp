#include <iostream>
using namespace std;

class Node{
  public :
    static int numEle;
    int data;
    Node *next;
};
int Node::numEle = 1;//Because there is head already declared

void Display(Node *list){
  while(list){
    cout << " -> " << list->data ;
    list = list->next;
  }
  cout << endl;
}

void RecDisplay(Node *list){
  if(list){
    RecDisplay(list->next);
    cout<<list->data;
  }
}
void InsertElement(Node *list,int ele){
  Node *newEle = new Node;
  while(list->next){
    list = list->next;
  }
  newEle->data = ele;
  newEle->next = nullptr;
  list->next = newEle;
  Node::numEle++;
}
int SumNodes(Node *list){
  int sum = 0;
  while(list){
    sum+=list->data;
    list = list->next;
  }
  return sum;
}
int MaxNode(Node *list){
  int max = 0;
  while(list){
    if(max < list->data){
      max = list->data;
    }
    list = list->next;
  }
  return max;
}
int Searching(Node *list, int value){
  int cpt = 0;
  while(list){
    if(list->data == value){
      break;
    }
    list = list->next;
    cpt++;
  }
  if(list==NULL){
    cpt = -1;
  }
  return cpt;
}

int main(){
  int num,ele;
  Node *head = new Node;
  Node *list = new Node;
  head->data = 2;
  head->next = nullptr;
  cout << "How much element to insert : ";
  cin >> num;
  for(int i = 0 ; i < num ; i++){
    cout << "Element " << i+1 << " : " << endl;
    cin >> ele;
    list = head;
    InsertElement(list,ele);
  }
  Display(head);
  cout << "Number of Nodes : " << Node::numEle << endl;
  cout << "Maximum : " << MaxNode(head) << endl;
  cout << "Sum : " << SumNodes(head) << endl;
  int res = Searching(head,4)+1;
  if(res == 0){
    cout << "Element 4 doesn't exist";
  }
  else{
    cout << "index of 4 : " << Searching(head,4)+1 << endl;
  }
  return 0;
}
