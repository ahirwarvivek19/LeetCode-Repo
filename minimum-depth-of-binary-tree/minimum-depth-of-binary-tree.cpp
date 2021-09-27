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
    int minDepth(TreeNode* root) {
        int MinDepth = INT_MAX;
        if(root == NULL) return 0;
        if(!root->left && !root->right) return 1;
        if(root->left) MinDepth = min(MinDepth, minDepth(root->left));
        if(root->right) MinDepth = min(MinDepth, minDepth(root->right));
        return MinDepth + 1;
    }
};