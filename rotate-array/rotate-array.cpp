class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        if(nums.size()<=1){
            return;   
        }
        reverse(nums.begin(),nums.end()-k);

        reverse(nums.end()-k,nums.end());

        reverse(nums.begin(),nums.end());
    }
};