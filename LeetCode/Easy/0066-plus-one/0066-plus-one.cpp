class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int val = 1;
        for(int i=digits.size() - 1; i>-1; i--){
            digits[i] += val;
            val = 0;
            if(digits[i] == 10){
                digits[i] = 0;
                val = 1;
            } 
        }
        if(val) digits.insert(digits.begin(), 1);
        return digits;
    }
};