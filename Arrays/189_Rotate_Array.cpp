/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // Handle k > n
        
        if (k == 0) return;
        
        // Reverse entire array
        reverse(nums, 0, n - 1);
        
        // Reverse first k elements
        reverse(nums, 0, k - 1);
        
        // Reverse remaining elements
        reverse(nums, k, n - 1);
    }
    
private:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};

int main() {
    Solution sol;
    
    // Test 1: [1,2,3,4,5,6,7], k=3 → [5,6,7,1,2,3,4]
    vector<int> test1 = {1, 2, 3, 4, 5, 6, 7};
    sol.rotate(test1, 3);
    cout << "Test 1: k=3 → [";
    for (int i = 0; i < test1.size(); i++) {
        cout << test1[i];
        if (i < test1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // Test 2: [-1,-100,3,99], k=2 → [3,99,-1,-100]
    vector<int> test2 = {-1, -100, 3, 99};
    sol.rotate(test2, 2);
    cout << "Test 2: k=2 → [";
    for (int i = 0; i < test2.size(); i++) {
        cout << test2[i];
        if (i < test2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // Test 3: [1,2,3], k=1 → [3,1,2]
    vector<int> test3 = {1, 2, 3};
    sol.rotate(test3, 1);
    cout << "Test 3: k=1 → [";
    for (int i = 0; i < test3.size(); i++) {
        cout << test3[i];
        if (i < test3.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // Test 4: [1,2], k=3 (k > n) → [2,1]
    vector<int> test4 = {1, 2};
    sol.rotate(test4, 3);
    cout << "Test 4: k=3 (k>n) → [";
    for (int i = 0; i < test4.size(); i++) {
        cout << test4[i];
        if (i < test4.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // Test 5: [1], k=1 → [1]
    vector<int> test5 = {1};
    sol.rotate(test5, 1);
    cout << "Test 5: k=1 (single) → [";
    for (int i = 0; i < test5.size(); i++) {
        cout << test5[i];
        if (i < test5.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}