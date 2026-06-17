class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size() - 2; i++){
            if(i && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] == 0){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++; while(left < right && nums[left - 1] == nums[left]) left++;
                }
                else if(nums[i] + nums[left] + nums[right] > 0){
                    right--; while(left < right && nums[right] == nums[right + 1]) right--;
                }
                else{
                    left++; while(left < right && nums[left - 1] == nums[left]) left++;
                }
            }
        }
        return ans;
    }
};