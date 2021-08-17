class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size()-1;
        int i=size;
        while(i>=0){
            if(digits[i]<9){
                digits[i]=digits[i]+1;
                return digits;
            }else{ 
                digits[i]=(digits[i]+1)%10; 
            }
            i--;
        } //insert 1 at the beginning of the vector (happens in conditions where all digits are 9)
		digits.insert(digits.begin(),1);
        return digits;
        
    }
};