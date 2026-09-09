#include<iostream>
using namespace std;

int factorial(int n) {
    // BASE CASE - Stop here
    if (n == 0 || n == 1) return 1;
    
    // RECURSIVE CASE - Call itself with smaller problem
    return n * factorial(n - 1);
}

int main(){
    cout << factorial(5) << endl;  // Output: 120
    return 0;
}