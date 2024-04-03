#include <iostream>

struct card{
  int face;
  int shape;
  int colors;
}cards[10];

using namespace std;

int main(){

  cards[0] = {0,1,1};
  cards[1] = {0,1,0};

  for (card x:cards){
    cout << x.shape << endl;
  }
  return 0;
}