#include <iostream>
using namespace std;
int main(){
  int A[5] = {2,4};
  int n = 3;
  int *p = new int[n];
  p[0] = {1};
  // p = new int[10];
  // p = {1,4,5};
  cout<<p[0];
  for(int x:A){
    cout <<x<<endl;
  }
  cout << 2[A];
  return 0;
}