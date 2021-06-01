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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        
        if(head1==NULL||head2==NULL)
        {
            return NULL;
        }
    
        ListNode * temp1 = head1;
        ListNode * temp2 = head2;
    
        while(temp1!=temp2)
        {
            temp1 = (temp1==NULL)?head2:temp1->next;
            temp2 = (temp2==NULL)?head1:temp2->next;

        }
    
        return temp1;
        
    }
};