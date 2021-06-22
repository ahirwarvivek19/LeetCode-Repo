class Solution {
public:
    
    int countDays(vector<int>& weights, int tot_cap) {
        int sum = 0;
        int res = 1;
        for (auto w : weights) 
        {
            sum += w;
            if (sum > tot_cap) 
            {
                ++res; 
                sum = w;
            }
        }
        return res;
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        
        int left = -1, right = 0;
        
        for(int i = 0; i < weights.size(); i++){
            left = max(left, weights[i]);
            right += weights[i];
        }
        
        while(left < right){
            int mid = left + (right-left) / 2;
            int days = countDays(weights, mid);
            // the capacity is too small
            if(days > D){
                left = mid+1;
            // }else if(days < D){ // the capacity is too large
            //     right = mid-1;
            }else{ // the capacity can meet condition, but we need to try smaller one
                right = mid;
            }
        }
        
        return left;
    }
};