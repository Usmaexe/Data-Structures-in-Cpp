#include <iostream>

using namespace std;

int main() {
    int A[5];
    char B[3] = {'a','w','z'};
    for (int i = 0; i < 5; i++) { 
        cout << "A[" << i << "]="; 
        cin >> A[i];
    }
    // I CAN ALSO USE PRINTF: 
    // cout << *A << *(B+2);

    for (int x:A){
        cout << x << endl;
    }

    printf("%d",*(A+2));

    return 0;
}
