/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {//3rd sol
        // Initialize slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse until fast and fast->next are not null
        while (fast != NULL && fast->next != NULL) {
            // Move slow by one step
            slow = slow->next;

            // Move fast by two steps
            fast = fast->next->next;

            // If they meet, loop is detected
            if (slow == fast) {
                // Reset slow to head
                slow = head;

                // Move both one step at a time to find starting point
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                // Return the start node of the loop
                return slow;
            }
        }

        // If no loop found, return NULL
        return NULL;
    }
};