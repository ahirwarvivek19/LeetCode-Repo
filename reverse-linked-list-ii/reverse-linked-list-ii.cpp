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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *revLL = new ListNode(0), *prev = revLL, *curr=NULL,*nxt=NULL;
        revLL -> next = head;
        for (int i = 0; i < left - 1; i++) {
            prev = prev -> next;
        }
        curr = prev -> next;
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = prev -> next;
            prev -> next = curr -> next;
            curr -> next = curr -> next -> next;
            prev -> next -> next = temp;
            
            // nxt = curr->next;
            // curr->next = prev;
            // prev = curr;
            // curr = nxt;
        }
        return revLL -> next;
        
//         ListNode * curr =  temp->next;
//         ListNode * prev = right;
//         ListNode * next = NULL;
//         while(curr!=right)
//         {
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }
//         temp->next= prev;
//         return head;
    }
};