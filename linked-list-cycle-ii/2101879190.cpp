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
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> hash; // 2nd sol
        ListNode* temp = head;

        while (temp != NULL) {
            if (hash.find(temp) != hash.end())
                return temp;

            hash.insert(temp);
            temp = temp->next;
        }

        return NULL;
    }
};