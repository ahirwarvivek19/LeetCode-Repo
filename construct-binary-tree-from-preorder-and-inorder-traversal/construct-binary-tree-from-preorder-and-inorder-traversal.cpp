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
    
    int idx=0;
    map<int,int> mp;
    
    TreeNode * CT(int st,int end,vector<int> &preorder)
    {
        if(st>end)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[idx]);
        int pos = mp[preorder[idx]];
        idx++;
        
        root->left = CT(st,pos-1,preorder);
        root->right = CT(pos+1,end,preorder);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n= inorder.size();
        
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        
        TreeNode * root = CT(0,n-1,preorder);
        
        return root;
        
    }
};