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
    ListNode* swapPairs(ListNode* head) {

        if(!head || !head->next) 
            return head;
        
        ListNode* p = head;
        ListNode* res = head->next;
        ListNode* q; ListNode* temp;
        
        while(true)
        {
            q = p->next;
            temp = q->next;
            q->next = p;
            
            if(temp == NULL || temp->next == NULL) {
                p->next = temp;
                break;
            }
            p->next = temp->next;
            p = temp;
        }
        return res;
    }
};