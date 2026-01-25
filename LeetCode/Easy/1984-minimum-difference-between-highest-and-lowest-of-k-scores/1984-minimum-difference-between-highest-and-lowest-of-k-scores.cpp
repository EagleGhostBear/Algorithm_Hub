class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = 1e9;
        sort(nums.begin(), nums.end());
        deque<int> dq;
        int left = 0, right = k - 1;
        for(int i=k - 1; i<nums.size(); i++){
            ans = min(ans, nums[right++] - nums[left++]);
        }
        return ans;
    }
};