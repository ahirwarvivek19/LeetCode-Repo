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
    int getDecimalValue(ListNode* head) {
        
        stack<int> st;
        
        while(head)
        {
            st.push(head->val);
            head = head->next;
        }
        int res = 0;
        int cnt = 0;
        while(!st.empty())
        {
            int x = st.top();
            st.pop();
            x*=pow(2,cnt);
            res+=x;
            cnt++;
        }
        return res;
    }
};