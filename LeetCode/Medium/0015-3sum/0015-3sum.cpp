class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size() - 2; i++){
            if(i && nums[i] == nums[i - 1]) continue;
            for(int j=i+1; j<nums.size() - 1; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int target = -1 * (nums[i] + nums[j]);
                int left = j + 1, right = nums.size() - 1, mid;
                while(left <= right){
                    mid = (left + right) / 2;
                    if(nums[mid] == target){
                        ans.push_back({nums[i], nums[j], nums[mid]});
                        break;
                    }
                    else if(nums[mid] < target) left = mid + 1;
                    else right = mid - 1;
                }
            }
        }
        return ans;
    }
};