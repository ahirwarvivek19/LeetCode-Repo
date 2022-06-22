// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
unordered_map<int, int> in_node_idx;
class Solution{
    public:
    Node *helper(int in[], int pre[], int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }
    int rootData = pre[preS];
    int root_index_in = in_node_idx[rootData];

    int linS = inS;
    int linE = root_index_in - 1;
    int lpreS = preS + 1;
    int lpreE = lpreS + linE - linS;
    int rinS = root_index_in + 1;
    int rinE = inE;
    int rpreS = lpreE + 1;
    int rpreE = preE;
    Node *root = new Node(rootData);
    root->right = helper(in, pre, rinS, rinE, rpreS, rpreE);
    root->left = helper(in, pre, linS, linE, lpreS, lpreE);
    return root;
}
    Node* buildTree(int in[],int pre[], int n)
    {
         for (int i = 0; i < n; i++)
    {
        in_node_idx[in[i]] = i;
    }
    return helper(in, pre, 0, n - 1, 0, n - 1);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends