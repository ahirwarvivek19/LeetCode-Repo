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
class mycomp{
    public:
        bool operator()(ListNode * a, ListNode *b)
        {
            return b->val < a->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode *, vector<ListNode*>,mycomp> pq;
        ListNode* mergedListHead  =NULL;
        ListNode* mergedListTail  =NULL;
        for(auto x: lists)
        {
            if(x)
            {
                pq.push(x);
            }
        }
        
        while(!pq.empty())
        {
            auto  u=pq.top();
            pq.pop();
            if(u->next)
            {
                pq.push(u->next);
            }
            
            if(mergedListHead==NULL)
            {
                mergedListHead = u;
                mergedListTail = u;
                mergedListTail->next= NULL;
            }
            else
            {
                mergedListTail->next = u;
                mergedListTail = u;
                mergedListTail->next = NULL;
            }
        }
        return mergedListHead;
        
    }
};