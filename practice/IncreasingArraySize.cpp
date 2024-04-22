#include <iostream>
using namespace std;
int main(){
  int *p = new int[5];
  p[0] = 4;
  p[1] = 2;
  p[2] = 5;
  p[3] = 1;
  p[4] = 0;
  int *q = new int[10];
  for(int i = 0 ; i < 5 ; i++){
    // q[i] = p[i];
    *(q+i) = *(p+i);
  }
  delete []p;
  p = q;
  q = NULL;
  
  return 0;
}