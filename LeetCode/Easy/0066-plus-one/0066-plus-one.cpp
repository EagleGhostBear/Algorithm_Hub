class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int up = 1;
        for(int i=digits.size() - 1; i>-1; i--){
            digits[i] += up;
            up = 0;
            if(digits[i] > 9){
                digits[i] = 0;
                up = 1;
            }
        }
        if(up) ans.push_back(1);
        for(auto n : digits) ans.push_back(n);
        return ans;
    }
};