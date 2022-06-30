// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int f(long long int n, vector<long long int> &dp)
    {
        if(n<=0)
            return 0;
        if(n<4)
            return dp[n]=1;
        if(n==4)
        {
            return dp[n]=2;
        }
        
        if(dp[n]!=-1)
            return dp[n];
        
        return dp[n]=f(n-1,dp)+f(n-4,dp);
        
    }

    long long int arrangeTiles(int N){
        // code here
        vector<long long int> dp(N+2,-1);
        return f(N,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends