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
     
    bool inorder(TreeNode* root,unordered_set<int> &s,int k)
    {
        if(root==NULL)
            return false;
        if(inorder(root->left,s,k))
            return true;
        if(s.find(k-root->val)!=s.end())
            return true;
        else
            s.insert(root->val);
        
        return inorder(root->right,s,k);
     }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return inorder(root,s,k);
    }
};