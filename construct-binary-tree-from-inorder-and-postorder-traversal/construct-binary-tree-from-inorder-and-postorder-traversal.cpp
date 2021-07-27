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
    
    TreeNode * CT(int st,int end,vector<int> &postorder)
    {
        if(st>end)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[idx]);
        int pos = mp[postorder[idx]];
        idx--;
        
        root->right = CT(pos+1,end,postorder);
        root->left = CT(st,pos-1,postorder);
        
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n= postorder.size();
        idx = (n-1);
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        
        TreeNode * root = CT(0,n-1,postorder);
        
        return root;
    }
};