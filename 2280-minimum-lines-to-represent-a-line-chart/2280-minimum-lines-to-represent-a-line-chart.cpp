class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        // vector<float> v(n-1);
        
        sort(stockPrices.begin(),stockPrices.end());
        // int j = 0;
        int cnt = 1;
        int n = stockPrices.size();
        if(n<=1)
        {
            return 0;
        }
        for(int i =1;i<n-1;i++)
        {
            
            long double x1 = stockPrices[i-1][0];
            long double y1 = stockPrices[i-1][1];
                
            long double x2 = stockPrices[i][0];
            long double y2 = stockPrices[i][1];
            
            
            long double x3 = stockPrices[i+1][0];  
            long double y3 = stockPrices[i+1][1];
            
            long double a = (long double)(y2-y1)/(x2-x1); //slope of line joining pts i , i 1
            long double b = (long double)(y3-y2)/(x3-x2);  // slope of line joining pts i+1,i
            
            if(a!=b){
                                         
                cnt++;
            }
            
        }
        return cnt;
    }
};