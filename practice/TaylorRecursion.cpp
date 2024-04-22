#include <iostream>
using namespace std;
float p=1,f=1;
float taylor(int m,int x){
  float r;
  if(x==0){
    return 1;
  }
  else{
    r = taylor(m,x-1);
    p = p * m;
    f = f * x;
    return r+p/f;
  }
}

int main(){
  int m=1,x=10;
  cout << taylort(m,x);
  return 0;
}