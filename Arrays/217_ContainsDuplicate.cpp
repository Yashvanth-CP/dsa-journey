/*
217. Contains Duplicate

Given an integer array nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
    public:

    bool containsDuplicate( vector<int> & nums){
         unordered_set<int> seen;

        for(int i =0; i< nums.size(); i++){
            if(seen.find(nums[i]) != seen.end()){
                return true;
            }
            seen.insert(nums[i]);
           
            }
            return false;
    }
};

int main(){
 Solution sol;
     vector<int> nums1 = {1, 2, 3, 1};
    bool result1 = sol.containsDuplicate(nums1);
    cout << "Test 1: " << (result1 ? "true" : "false") << endl;  // Expected: true
    
    // Test 2
    vector<int> nums2 = {1, 2, 3, 4};
    bool result2 = sol.containsDuplicate(nums2);
    cout << "Test 2: " << (result2 ? "true" : "false") << endl;  // Expected: false
    
    // Test 3
    vector<int> nums3 = {99, 99};
    bool result3 = sol.containsDuplicate(nums3);
    cout << "Test 3: " << (result3 ? "true" : "false") << endl;  // Expected: true
    
    
    return 0;
}