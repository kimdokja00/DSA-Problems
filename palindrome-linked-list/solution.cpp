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
    bool isPalindrome(ListNode* head) {
        vector<int> node;
        ListNode* temp = head;
        if(head == NULL || head-> next == NULL){
            return true;
        }
        while(temp!= NULL ){
            node.push_back(temp->val);
            temp = temp ->next;
        }
        int n = node.size();
        for (int i =0;i<n/2;i++){
            if(node[i]!=node[n-1-i]){
                return false;
            }
        }
        return true;
    }
};