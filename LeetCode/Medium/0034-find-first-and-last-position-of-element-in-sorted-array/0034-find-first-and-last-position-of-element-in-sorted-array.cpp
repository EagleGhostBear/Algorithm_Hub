class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        if(nums.size() < 1) return ans;
        int left = 0, right = nums.size() - 1, mid;
        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] == target){
                ans[0] = mid;
                right = mid - 1;
            }
            else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        left = 0, right = nums.size() - 1, mid;
        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] == target){
                ans[1] = mid;
                left = mid + 1;
            }
            else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return ans;
    }
};