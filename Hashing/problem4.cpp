#include <iostream>
#include <map>
using namespace std;

int main() {

    int n;
    cin >> n;

    int arr[n];

    // Input array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Pre-compute frequency
    unodered_map<int, int> mpp;

    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    // Number of queries
    int q;
    cin >> q;

    while (q--) {

        int number;
        cin >> number;

        // Fetch frequency
        cout << mpp[number] << endl;
    }

    return 0;
}