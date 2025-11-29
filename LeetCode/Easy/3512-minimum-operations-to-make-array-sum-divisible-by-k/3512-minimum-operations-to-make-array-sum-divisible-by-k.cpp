class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(auto n : nums) ans += n;
        return ans % k;
    }
};