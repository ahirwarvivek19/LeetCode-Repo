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
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        if(head==NULL)  return NULL;
        while(fast->next&&fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                ListNode * r1 = head;
                ListNode * r2 = slow;
                while(r1!=r2)
                {
                    r1 = r1->next;
                    r2 = r2->next;
                }
                return r1;
        
            }
        }
        return NULL;
      
    }
};