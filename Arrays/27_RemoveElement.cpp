#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

int main() {
    Solution sol;
    
    // Test 1
    vector<int> test1 = {0,1,2,2,3,0,4,2};
    int k1 = sol.removeElement(test1, 2);
    cout << "Test 1: k=" << k1 << ", nums=[";
    for(int i = 0; i < k1; i++) {
        cout << test1[i];
        if(i < k1-1) cout << ",";
    }
    cout << "]" << endl;
    
    // Test 2
    vector<int> test2 = {3,2,2,3};
    int k2 = sol.removeElement(test2, 3);
    cout << "Test 2: k=" << k2 << ", nums=[";
    for(int i = 0; i < k2; i++) {
        cout << test2[i];
        if(i < k2-1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}