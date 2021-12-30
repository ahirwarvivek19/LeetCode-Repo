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

    int f(TreeNode* root, int &sum)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lefts = f(root->left,sum);
        int rights = f(root->right,sum);
        sum+=abs(lefts-rights);
        return lefts+rights+root->val;
    }
    
    
public:
    int findTilt(TreeNode* root) {
        
        int sum = 0;
        
        f(root,sum);
        
        return sum;
        
    }
};