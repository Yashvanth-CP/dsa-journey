/*
Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        if (head == nullptr || 
            head->next == nullptr || 
            head->next->next == nullptr) {
            return ans;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;
        int firstCritical = -1;
        int lastCritical = -1;
        int minDistance = INT_MAX;

        while (curr->next != nullptr) {

            bool isCritical =
                (curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val);

            if (isCritical) {

                if (firstCritical == -1) {
                    firstCritical = index;
                } 
                else {
                    minDistance = min(
                        minDistance,
                        index - lastCritical
                    );
                }

                lastCritical = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        if (firstCritical == lastCritical) {
            return ans;
        }

        int maxDistance = lastCritical - firstCritical;

        return {minDistance, maxDistance};
    }
};

int main() {

    // Create linked list:
    // 5 -> 3 -> 1 -> 2 -> 5 -> 1 -> 2

    ListNode* head = new ListNode(5);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(2);

    Solution sol;

    vector<int> result =
        sol.nodesBetweenCriticalPoints(head);

    cout << "Minimum distance: " << result[0] << endl;
    cout << "Maximum distance: " << result[1] << endl;

    return 0;
}