/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
vector<int> v;
class Solution {
public:
    void f(Node * src)
    {
        if(src==NULL)
            return;
        v.push_back(src->val);
        
        for(auto x: src->children)
        {
                f(x);
        }
    }
    
    vector<int> preorder(Node* root) {
        v.resize(0);
        f(root);
        
        return v;
    }
};