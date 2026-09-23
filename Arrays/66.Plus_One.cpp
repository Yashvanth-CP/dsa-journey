#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;  // We're adding 1
        
        // Start from the LAST digit
        for(int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + carry;  // Add carry to current digit
            
            if(sum == 10) {
                digits[i] = 0;  // Set current to 0
                carry = 1;      // Carry 1 to next
            } else {
                digits[i] = sum;  // Set to sum
                carry = 0;        // No carry
                break;            // We're done!
            }
        }
        
        // If carry remains, add digit at front
        if(carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};

int main() {
    Solution sol;
    
    // Test 1: Simple case
    vector<int> test1 = {1, 2, 3};
    vector<int> result1 = sol.plusOne(test1);
    cout << "Test 1: [1,2,3] → [";
    for(int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if(i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // Test 2: Carry propagates
    vector<int> test2 = {1, 2, 9};
    vector<int> result2 = sol.plusOne(test2);
    cout << "Test 2: [1,2,9] → [";
    for(int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if(i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // Test 3: All 9s (new digit needed)
    vector<int> test3 = {9, 9, 9};
    vector<int> result3 = sol.plusOne(test3);
    cout << "Test 3: [9,9,9] → [";
    for(int i = 0; i < result3.size(); i++) {
        cout << result3[i];
        if(i < result3.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // Test 4: Single digit
    vector<int> test4 = {5};
    vector<int> result4 = sol.plusOne(test4);
    cout << "Test 4: [5] → [";
    for(int i = 0; i < result4.size(); i++) {
        cout << result4[i];
        if(i < result4.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // Test 5: Single 9
    vector<int> test5 = {9};
    vector<int> result5 = sol.plusOne(test5);
    cout << "Test 5: [9] → [";
    for(int i = 0; i < result5.size(); i++) {
        cout << result5[i];
        if(i < result5.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}