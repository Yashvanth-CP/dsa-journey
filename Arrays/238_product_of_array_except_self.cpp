/*
238_product_of_array_except_self.cpp

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);
        
        // Step 1: Calculate prefix products (product of all elements to the left)
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }
        
        // Step 2: Calculate suffix products (product of all elements to the right)
        // and multiply with prefix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        
        return answer;
    }
};

int main() {
    Solution sol;
    
    // Test 1: [1,2,3,4] → [24,12,8,6]
    vector<int> test1 = {1, 2, 3, 4};
    vector<int> result1 = sol.productExceptSelf(test1);
    cout << "Test 1: [1,2,3,4] → [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // Test 2: [-1,1,0,-3,3] → [0,0,9,0,0]
    vector<int> test2 = {-1, 1, 0, -3, 3};
    vector<int> result2 = sol.productExceptSelf(test2);
    cout << "Test 2: [-1,1,0,-3,3] → [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // Test 3: [2,3,4,5] → [60,40,30,24]
    vector<int> test3 = {2, 3, 4, 5};
    vector<int> result3 = sol.productExceptSelf(test3);
    cout << "Test 3: [2,3,4,5] → [";
    for (int i = 0; i < result3.size(); i++) {
        cout << result3[i];
        if (i < result3.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}