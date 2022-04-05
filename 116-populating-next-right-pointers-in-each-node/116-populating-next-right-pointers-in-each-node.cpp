/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
        {
            return root;
        }
        Node * head = root;
        queue<Node*> q;
        q.push(head);
        while(!q.empty())
        {
            int ss = q.size();
            Node * prev = q.front();
            q.pop();
            if(prev->left)
            {
                q.push(prev->left);
            }
            
            if(prev->right)
            {
                q.push(prev->right);
            }
            
            for(int i=1;i<ss;i++)
            {
                Node * curr = q.front();
                q.pop();
                
                if(curr->left)
                {
                    q.push(curr->left);
                }

                if(prev->right)
                {
                    q.push(curr->right);
                }
                
                prev->next = curr;
                prev = curr;
            }
            
        }
        return root;
        
    }
};