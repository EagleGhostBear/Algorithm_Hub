class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int ans = 0, total = 0, now = 0;
        for(int i=0; i<nums.size(); i++) total += nums[i];
        for(int i=0; i<nums.size() - 1; i++){
            now += nums[i];
            total -= nums[i];
            if(now % 2 == total % 2) ans++;
        }
        return ans;
    }
};