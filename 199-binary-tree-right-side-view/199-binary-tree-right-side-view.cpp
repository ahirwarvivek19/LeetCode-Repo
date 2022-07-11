/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int ss = q.size();
            for(int i = 0;i<ss-1;i++)
            {
                auto x = q.front();
                q.pop();
                if(x->left)
                {
                    q.push(x->left);
                }
                if(x->right)
                {
                    q.push(x->right);
                }
                
            }
            auto x = q.front();
            q.pop();
            if(x->left)
            {
                q.push(x->left);
            }
            if(x->right)
            {
                q.push(x->right);
            }
            v.push_back(x->val);
        }
        return v;
    }
};