#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        Find the single number using XOR bitwise operation.
        
        Key insight:
        - a ^ a = 0 (XOR of same numbers = 0)
        - a ^ 0 = a (XOR with 0 = number itself)
        
        So: num1 ^ num2 ^ num1 ^ num3 ^ num2 = num3
        
        Time: O(n)
        Space: O(1)
        */
        int result = 0;
        
        for (int num : nums) {
            result ^= num;  // XOR each number
        }
        
        return result;
    }
};

// Main function with test cases
int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {2, 2, 1};
    cout << "Input: [2, 2, 1]" << endl;
    cout << "Output: " << sol.singleNumber(nums1) << endl;  // Expected: 1
    cout << endl;
    
    // Test case 2
    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "Input: [4, 1, 2, 1, 2]" << endl;
    cout << "Output: " << sol.singleNumber(nums2) << endl;  // Expected: 4
    cout << endl;
    
    // Test case 3
    vector<int> nums3 = {1};
    cout << "Input: [1]" << endl;
    cout << "Output: " << sol.singleNumber(nums3) << endl;  // Expected: 1
    cout << endl;
    
    // Test case 4
    vector<int> nums4 = {1, 3, 1, 3, 5};
    cout << "Input: [1, 3, 1, 3, 5]" << endl;
    cout << "Output: " << sol.singleNumber(nums4) << endl;  // Expected: 5
    cout << endl;
    
    // Test case 5
    vector<int> nums5 = {-1, -1, 0, 1, 1, 2, 2};
    cout << "Input: [-1, -1, 0, 1, 1, 2, 2]" << endl;
    cout << "Output: " << sol.singleNumber(nums5) << endl;  // Expected: 0
    
    return 0;
}