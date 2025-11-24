class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = 0;
        vector<bool> ans;
        for(int i=0; i<nums.size(); i++){
            n = ((n << 1) | nums[i]) % 5;
            if(n) ans.push_back(false);
            else ans.push_back(true);
        }
        return ans;
    }
};