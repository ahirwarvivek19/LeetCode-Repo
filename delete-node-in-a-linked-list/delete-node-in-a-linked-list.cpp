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
    void deleteNode(ListNode* node) {
        ListNode * temp =node;
        int x;
        
        node->val = node->next->val;
        
        node->next = temp->next->next;
        
        
        
        
    }
};