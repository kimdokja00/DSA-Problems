/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* end = head;
        ListNode* first = head;
        int count = 0;
        if(head == NULL){
            return head;
        }
        while(end!=NULL&&end->next != NULL){
            end = end-> next;
            count++;
        }
        int n = count;
        int x = count-1;
        for(int i = 0 ; i <= n/2;i++){
            int temp;
            count = x;
            temp = first->val;
            first->val = end-> val;
            end -> val = temp;

            first = first-> next;
            end = head;

            while(count>0){
                end = end->next;
                count--;
            }
            x--;
        }
        return head;
    }
};