#include <iostream>
#include <stdlib.h>

using namespace std;


struct Rectangle{
  int length;
  int breadth;
};
int main(){
  Rectangle *p;
  p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
  p->length = 5;
  p->breadth = 10;
  cout << p->length; 
  return 0;
}