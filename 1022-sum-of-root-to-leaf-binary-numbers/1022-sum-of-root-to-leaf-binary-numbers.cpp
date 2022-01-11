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
int s;
class Solution {
public:
    
    void dfs(TreeNode* root, int sum)
    {
        
        if(root==NULL)
        {
            return ;
        }
        sum = (sum << 1) + root->val;
        if(root->left==NULL && root->right==NULL)
        {
             
            s+=sum;
            return ;
        }
        
        dfs(root->left,sum);
        
        dfs(root->right,sum);
        
        return ;
        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        s=0;
        dfs(root,0);
        return s;
    }
};