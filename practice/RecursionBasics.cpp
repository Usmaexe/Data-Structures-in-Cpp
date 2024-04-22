#include <iostream>
#include <vector>
using namespace std;
int rec(int n){
  if(n==1) return n;

  // else return sum(n-1)+n; // SUM
  else return rec(n-1)*n; // FACTORIAL
  
}

int pow(int m,int n){
  if(n==1){
    return m;
  }
  else{
    return pow(m,n-1)*m;
  }
}
typedef vector <int> vi;
int main(){
  vi k;
  int num,m,n;
  cin>>num>>m>>n;
  cout<<rec(num)<<endl;
  cout<<pow(m,n);
}