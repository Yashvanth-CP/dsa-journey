#include<iostream>
#include<cstdio>
using namespace std;

int cnt = 0;
void print(){
    if (cnt == 3) return;
    cout << 1 << endl;
    cnt++;
    print();
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w", stdout);
    #endif

    print();
    return 0;
}