class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans = 0, sz = nums.size() - 1;
        sort(nums.begin(), nums.end());
        for(int i=0; i<=sz/2; i++){
            ans = max(ans, nums[i] + nums[sz - i]);
        }
        return ans;
    }
};