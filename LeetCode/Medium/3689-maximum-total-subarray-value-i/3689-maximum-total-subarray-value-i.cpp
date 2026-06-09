class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long ans = nums.back() - nums.front();
        return ans * k;
    }
};