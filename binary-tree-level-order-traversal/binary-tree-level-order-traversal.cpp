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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        
        if(root == NULL) return v;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            
            vector<int> level;
            
            for(int i=0; i<size; i++)
            {
                TreeNode* u = q.front();
                q.pop();

                if(u->left!=NULL) q.push(u->left);
                if(u->right!=NULL) q.push(u->right);
                level.push_back(u->val);
            }
            
            v.push_back(level);

        }
        return v;
    }
};