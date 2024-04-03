#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
  int a = 10;
  int *p;
  p = &a;
  cout << "a = " << a << " The adress of variable a via the pointer : " << p << endl;
  printf("Diffrent repsentation of the adress : %d,%X\n",p,p);
  cout << "Pointer on the first element of an array : " << endl;
  int A[5] = {1,2,3,4,5};
  int *ptr= A;
  printf("%d\n",*ptr);
  for (int *pt = A ; pt < A+sizeof(A)/sizeof(int) ; pt++){
    printf("A[%d]%d\n",pt-A,*pt);
  }

  //ALLOCATION OF MEMORY:
  // int *ptr2 = (int *)malloc(5*sizeof(int)); // C syntax
  int *ptr2 = new int[5];// Cpp syntax
  for(int i = 0 ; i < 5 ; i++){
    cout <<" ptr["<< i<<"]=";
    cin >> ptr2[i];
  }
  for(int i = 0 ; i < 5 ; i++){
    cout << ptr2[i];
  }
  // free(ptr2);// C Syntax
  delete [] ptr2;//cpp syntax

}