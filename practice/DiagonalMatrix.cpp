#include <iostream>
using namespace std;
class Diagonal{
  private : 
    int n;//n=m
    int *A;
  public :
    Diagonal(int n){
      this->n = n;
      A = new int [n];

    } //ONLY ALLOCATION WITHOUT INTITIALIZATION
    Diagonal(int n, int *tab){
      this->n = n;
      A = new int [n];
      for(int i = 0 ; i < n ; i++){
        A[i] = tab[i];
      }
    }
    void set(int i,int j, int value);
    int get(int i,int j);
    ~Diagonal();
};

void Diagonal::set(int i, int j,int value){
  if(i==j){
    A[i] = value;
  }
  else
    cout<<"impossible operation for a diagonal matrix";
}

int Diagonal::get(int i,int j){
  if(i==j){
    return A[i];
  }
  else{
    return 0;
  }
}

Diagonal::~Diagonal(){
  delete[]A;
}

int main(){
  int A[3] = {4,5,6};
  Diagonal amin(3,A);
  cout << amin.get(1,1);
  return 0;
}