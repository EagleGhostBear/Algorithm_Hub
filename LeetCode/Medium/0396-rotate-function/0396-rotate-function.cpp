class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = 0, tot = 0, prev = 0;
        for(auto n : nums) tot += n;
        for(int i=0; i<nums.size(); i++){
            prev += nums[i] * i;
        }
        ans = prev;
        for(int i=nums.size() - 1; i>-1; i--){
            int now = prev + tot - (nums[i] * nums.size());
            ans = max(ans, now);
            prev = now;
        }
        return ans;
    }
};