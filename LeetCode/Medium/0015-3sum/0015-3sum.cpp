class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size() - 2; i++){
            if(i && nums[i] == nums[i - 1]) continue;
            vector<bool> visited(2e5 + 1);
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] == 0){
                    if(!visited[nums[left] + 1e5]) ans.push_back({nums[i], nums[left], nums[right]});
                    visited[nums[left] + 1e5] = true;
                    left++;
                }
                else if(nums[i] + nums[left] + nums[right] > 0) right--;
                else left++;
            }
        }
        return ans;
    }
};