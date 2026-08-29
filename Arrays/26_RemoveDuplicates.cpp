#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int i = 1;  
        
        for(int j = 1; j < nums.size(); j++) {
           
            if(nums[j] != nums[j-1]) {
                nums[i] = nums[j];
                i++;
            }
        }
        
        return i; 
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {1, 1, 2};
    int k1 = sol.removeDuplicates(nums1);
    cout << "k = " << k1 << ", nums = [";
    for(int i = 0; i < k1; i++) {
        cout << nums1[i];
        if(i < k1-1) cout << ", ";
    }
    cout << "]" << endl;
    
    // Test case 2
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = sol.removeDuplicates(nums2);
    cout << "k = " << k2 << ", nums = [";
    for(int i = 0; i < k2; i++) {
        cout << nums2[i];
        if(i < k2-1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}