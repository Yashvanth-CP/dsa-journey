#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long expected_sum = (long long)n * (n + 1) / 2;
        long long actual_sum = 0;

        for (int num : nums) {
            actual_sum += num;
        }

        return expected_sum - actual_sum;
    }
};

int main() {
    vector<int> nums = {3, 0, 1};

    Solution solution;

    int result = solution.missingNumber(nums);

    cout << "Missing number: " << result << endl;

    return 0;
}