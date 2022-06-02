// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool dfs(int i,int j,vector<vector<int>>&m,vector<vector<int>>&ans)
    {
    
        int r = m.size();
        int c = m[0].size();
        if(i<0||j<0||i>=r||j>=c)
        {
            return false;
        }
        if(i==r-1&&j==c-1)
        {
            ans[i][j] = 1;
            return true;
        }
        
        if(m[i][j]!=0)
        {
            for(int k=1;k<=m[i][j];k++)
            {
                if(dfs(i,j+k,m,ans)||dfs(i+k,j,m,ans))
                {
                    ans[i][j] = 1;
                    return true;
                    
                }
                
            }
        }
        return false;
    }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&m){
	   // Code here
	   int r = m.size();
        int c = m[0].size();
	   vector<vector<int>> ans(r,vector<int>(c,0));
	   if(dfs(0,0,m,ans))
	    return ans;
	   else return {{-1}};
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends