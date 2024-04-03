#include <iostream>

using namespace std;

struct Rect{
  int length;
  int breadth;
};

void swapp(struct Rect *r){
  int s;
  s = r->length;
  r->length = r->breadth;
  r->breadth = s;
}

int main(){
  struct Rect rectangle = {10,4};
  // struct Rect *pt;
  swapp(&rectangle);
  cout << rectangle.length;
  
  return 0;
}