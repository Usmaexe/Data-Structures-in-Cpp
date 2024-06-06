#include <bits/stdc++.h>
using namespace std;

struct Node{
  int col;
  int val;
  Node *next;
}*head=NULL;


void Insert(int val,int col,int pos){
  Node *newEle = new Node;
  if(pos==1){
    newEle->val = val;
    newEle->col = col;
    newEle->next = head;
    head = newEle;
  }
  else{
    newEle->val = val;
    newEle->col = col;
    for(int i = 1 ; i < pos-1 ; i++){
      head = head->next;
    }
    newEle->next = head->next;
    head->next = newEle;
  }
}

int main(){
  int t,col,val;
  cout << "Number Of Lines :";
  cin>>t;
  Node *matrix[t];
  matrix[0] = new Node;
  Insert(10,1,1);
  Insert(3,4,2);
  matrix[0] = head;
  head=nullptr;

  matrix[1] = new Node;
  Insert(10,1,1);
  Insert(3,4,2);
  matrix[1] = head;

  Node *current = new Node;

  cout << "before displaying"<<endl;
  for(int i = 0 ; i < t ; i++){
    current = matrix[i];
    cout<< "Line " << i+1 << ":"<<endl;
    while(current!=nullptr){
        cout<<current->val<< " " <<current->col<<endl;
        current = current->next;
    }
    cout<<endl;
  }

  return 0;
}
