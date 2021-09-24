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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
        {
            return head;
        }
        ListNode * prev = NULL;
        ListNode * curr = head;
        ListNode * nxt = NULL;
        int i= 0;
        while(curr->next!=NULL)
        {
            
            nxt = curr->next;
            if(curr->val==nxt->val)
            {
                curr->next = nxt->next;
            }
            else
            {
                curr = curr->next;
            }
        }
        
        return head;
    }
};