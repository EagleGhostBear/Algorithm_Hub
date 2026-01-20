class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int val = -1;
            for(int j=1; j<nums[i]; j++) if((j | j + 1) == nums[i]){
                val = j;
                break;
            }
            ans.push_back(val);
        }
        return ans;
    }
};