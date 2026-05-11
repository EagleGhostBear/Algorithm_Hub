class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> cnt(nums.size(), 0);
        for(int i=nums.size() - 2; i>-1; i--) if(target >= abs(nums.back() - nums[i])) cnt[i] = 1;
        for(int i=nums.size() - 2; i>0; i--) if(cnt[i]) {
            for(int j=i-1; j>-1; j--) if(target >= abs(nums[j] - nums[i])) cnt[j] = max(cnt[j], cnt[i] + 1);
        }
        if(cnt.front() == 0) return -1;
        return cnt.front();
    }
};