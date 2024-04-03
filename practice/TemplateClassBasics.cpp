#include <iostream>

using namespace std;

template <class T>
class Rectangle{
  private :
    T length;
    T breadth;
  public:
    Rectangle();
    Rectangle(T l,T b);
    T area();
};

template <class T>
Rectangle<T>::Rectangle(){
  length = 0;
  breadth = 0;
}

template <class T>
Rectangle<T>::Rectangle(T l, T b){
  this->length = l;
  this->breadth = b;
}


template <class T>
T Rectangle<T>::area(){
  return length*breadth;
}

int main(){
  Rectangle <int>R1(5,10);
  Rectangle <float> R2(10.42,145.51);
  cout << "Rectangle1's area : " << R1.area() << endl;
  cout << "Rectangle2's area : " << R2.area();
}