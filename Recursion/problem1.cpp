#include<iostream>
using namespace std;


void f(int i, int n){
    if (i > n){
        return;
    }

    cout << " Raj " << endl;
    f(i+1, n);
}

int main(){
    int n, i;
    cin >> n;
    f(1, 3);
}
