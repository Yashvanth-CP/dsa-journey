#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = -1;

        // Find first zero
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        if (j == -1)
            return;

        // Move non-zero elements forward
        for (int i = j + 1; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

int main() {
    Solution sol;
    
    // Test 1: [0,1,0,3,12] → [1,3,12,0,0]
    vector<int> test1 = {0, 1, 0, 3, 12};
    sol.moveZeroes(test1);
    cout << "Test 1: ";
    for (int x : test1) cout << x << " ";
    cout << endl;
    
    // Test 2: [0] → [0]
    vector<int> test2 = {0};
    sol.moveZeroes(test2);
    cout << "Test 2: ";
    for (int x : test2) cout << x << " ";
    cout << endl;
    
    // Test 3: [1,2,3] → [1,2,3] (no zeros)
    vector<int> test3 = {1, 2, 3};
    sol.moveZeroes(test3);
    cout << "Test 3: ";
    for (int x : test3) cout << x << " ";
    cout << endl;
    
    // Test 4: [0,0,1] → [1,0,0]
    vector<int> test4 = {0, 0, 1};
    sol.moveZeroes(test4);
    cout << "Test 4: ";
    for (int x : test4) cout << x << " ";
    cout << endl;
    
    return 0;
}