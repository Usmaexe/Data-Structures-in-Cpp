#include <iostream>
using namespace std;

class Node{
  public :
    static int numEle;
    int data;
    Node *next;
};
int Node::numEle = 0;//Because there is head already declared

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
void Insert(Node *&list, int ele,int pos){
  Node *newEle = new Node;
  if(pos==1){
    newEle->data = ele;
    newEle->next = list;
    list = newEle;
  }
  else{
    Node *head = list;
    newEle->data = ele;
    for(int i = 1 ; i < pos-1 ; i++){
      head = head->next;
    }
    newEle->next = head->next;
    head->next = newEle;
  }
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

void Delete(Node *list,int value){

    bool found =false;
    if(list->data==value){
        list = nullptr;
        cout << "Element Deleted";
        Node::numEle--;
        found =true;
    }
    else{
        Node *head = list->next;
        Node *prev = list;
        while(head!=NULL){

            if(head->data==value){
                prev->next = head->next;
                head = head->next;
                cout << "Element Deleted";
                Node::numEle--;
                found = true;
                //Assuming that the list might contain duplicated elements
            }
            else{
                prev = head;
                head = head->next;

            }
        }
    }
    if(!found){
        cout << "Element doesn't exist ";
    }
    cout << endl << endl;
}

//There is multiple methodes to do so but here reversing using sliding pointers is been used
void Reverse(Node *&head){
    Node *after = head->next;
    Node *temp = new Node;
    head->next = nullptr;
    while(after!=nullptr){
        temp = after->next;
        after->next = head;
        head = after;
        after = temp;
    }
}

void ReverseUsingRec(Node *&head,Node *p, Node *q){
    if(q!=NULL){
        ReverseUsingRec(head,q,q->next);
        q->next = p;
    }
    else{
        head = p;
    }
}

void Concatenate(Node *head, Node*head2){
  while(head->next!=nullptr){
    head = head->next;
  }
  head->next = head2;
}

void Merge(Node *&third,Node *first, Node *second){
  Node *last;
  if(first->data<second->data){
    third = last = first;
    first = first->next;
    third->next = NULL; 
  }
  else{
    third = last = second;
    second = second->next;
    third->next = NULL;
  }
  while(first && second){
    if(first->data<second->data){
      last->next = first;
      last = first;
      first = first->next;
      last->next = NULL;
    }
    else{
      last->next = second;
      last = second;
      second = second->next;
      last->next = NULL;
    }
  }
  if(first) last->next = first;
  if(second) last->next = second;
  // return third;
}

int main(){
  int num,ele;
  Node *head = new Node;
  head = nullptr;

  /// INSERTING AND DISPLAYING
  Insert(head,1,1);
  cout << "How much element to insert : ";
  cin >> num;
  for(int i = 1 ; i <= num ; i++){
    cout << "Element " << i+1 << " : " << endl;
    cin >> ele;
    Insert(head,ele,i+1);
  }
  Display(head);
  cout << "Insert At index 1 : ";
  cin>>ele;
  Insert(head,ele,1);
  Display(head);


  ///NUMBER OF NODES
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

  /// DELETE SPECIFIC ELEMENT
  // int del;
  // cout << "\n\nElement to delete :";
  // cin >> del;
  // Delete(head,del);
  // Display(head);

  // ///REVERSE
  // Reverse(head);
  // Display(head);
  // ReverseUsingRec(head,nullptr,head);
  // Display(head);


  //CONCATENATE
  Node *head2 = new Node;
  head2 = nullptr;
  Insert(head2,4,1);
  for(int i = 1 ; i <= 3 ; i++){
    Insert(head2,i*5,i+1);
  }
  // Concatenate(head,head2);
  // Display(head);
  // cout<< head->data;
  // cout<< head2->data;

  ///MERGING
  Display(head2);
  Node *third = new Node;
  Merge(third,head,head2);
  Display(third);
  return 0;
}
