class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 == 0){ans.push_back(-1); continue;}
            int val = 1;
            while((val & nums[i]) == val) val = val * 2 + 1;
            val /= 2;
            if(nums[i] - val){
                if(val > 1) ans.push_back(nums[i] - val + (val / 2));
                else ans.push_back(nums[i] - 1);
            }
            else ans.push_back(val / 2);
        }
        return ans;
    }
};