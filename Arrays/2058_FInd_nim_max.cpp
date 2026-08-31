/*
Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int h = min(height[left], height[right]);

            int area = width * h;
            maxWater = max(maxWater, area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxWater;
    }
};

int main() {
    Solution sol;

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int result = sol.maxArea(height);

    cout << "Maximum water: " << result << endl;

    return 0;
}