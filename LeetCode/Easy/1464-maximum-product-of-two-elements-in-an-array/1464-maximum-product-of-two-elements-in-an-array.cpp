class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        return (nums[sz - 1] - 1) * (nums[sz - 2] - 1);
    }
};