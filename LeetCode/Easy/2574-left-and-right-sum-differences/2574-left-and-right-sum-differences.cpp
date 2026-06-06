class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int left = 0, right = 0;
        vector<int> ans;
        for(auto n : nums) right += n;
        for(int i=0; i<nums.size(); i++){
            right -= nums[i];
            ans.push_back(abs(right - left));
            left += nums[i];
        }
        return ans;
    }
};