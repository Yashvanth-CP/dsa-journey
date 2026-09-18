#include<iostream>
using namespace std;

int d(int n){
    if(n == 0 || n == 1){
        cout << "the given number is factorial is 1" << endl;
    return 1;
    }
    return d(n-1) * n;
}
int main(){
    int num = 10;
cout << "The factorial of " << num << " is " << d(num) << endl;

return 0;
}
