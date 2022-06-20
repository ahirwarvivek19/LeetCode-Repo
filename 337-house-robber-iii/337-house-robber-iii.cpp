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
map<pair<TreeNode *,bool >,int> mp;
class Solution {
public:
    int dfs(TreeNode* root, bool par)
    {
        if(root==NULL)
            return 0;
        if(mp.find({root,par})!=mp.end())
            return mp[{root,par}];
        
        int sum =0;
        if(!par)
            sum = root->val + dfs(root->left,1)+dfs(root->right,1);
        sum = max(sum,dfs(root->left,0)+dfs(root->right,0));
        
        return mp[{root,par}] = sum;
        
    }
    int rob(TreeNode* root) {
        // c1=0,c2=0;
        return  dfs(root,0);
        
    }
};