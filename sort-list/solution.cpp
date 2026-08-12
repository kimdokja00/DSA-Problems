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
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        vector<int> res;
        while(temp!=NULL){
            res.push_back(temp->val);
            temp = temp->next;
        }
        sort(res.begin(),res.end());

        temp = head;
        int n = 0;
        while(temp != NULL){
            temp->val = res[n];
            temp = temp->next;
            n++;
        }
        return head;
    }
};