#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);  // Dummy node
        ListNode* current = dummy;           // Pointer to build result
        
        while(list1 != NULL && list2 != NULL) {  // While both lists have nodes
            if(list1->val <= list2->val) {
                current->next = list1;       // Attach smaller node
                list1 = list1->next;         // Move list1 forward
            } else {
                current->next = list2;       // Attach smaller node
                list2 = list2->next;         // Move list2 forward
            }
            current = current->next;         // Move current forward
        }
        
        // Attach remaining nodes
        if(list1 != NULL) {
            current->next = list1;
        } else {
            current->next = list2;
        }
        
        return dummy->next;  // Skip dummy, return actual result
    }
};

// Helper function to create linked list from array
ListNode* createList(int arr[], int n) {
    if(n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for(int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while(current != NULL) {
        cout << current->val << " → ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Solution sol;
    
    // Test Case 1: [1,2,4] and [1,3,4]
    cout << "Test Case 1:" << endl;
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    ListNode* list1 = createList(arr1, 3);
    ListNode* list2 = createList(arr2, 3);
    
    cout << "List1: ";
    printList(list1);
    cout << "List2: ";
    printList(list2);
    
    ListNode* result1 = sol.mergeTwoLists(list1, list2);
    cout << "Merged: ";
    printList(result1);
    cout << endl;
    
    // Test Case 2: [] and []
    cout << "Test Case 2:" << endl;
    ListNode* list3 = createList(arr1, 0);
    ListNode* list4 = createList(arr2, 0);
    
    cout << "List1: ";
    printList(list3);
    cout << "List2: ";
    printList(list4);
    
    ListNode* result2 = sol.mergeTwoLists(list3, list4);
    cout << "Merged: ";
    printList(result2);
    cout << endl;
    
    // Test Case 3: [] and [0]
    cout << "Test Case 3:" << endl;
    int arr3[] = {0};
    ListNode* list5 = createList(arr1, 0);
    ListNode* list6 = createList(arr3, 1);
    
    cout << "List1: ";
    printList(list5);
    cout << "List2: ";
    printList(list6);
    
    ListNode* result3 = sol.mergeTwoLists(list5, list6);
    cout << "Merged: ";
    printList(result3);
    
    return 0;
}