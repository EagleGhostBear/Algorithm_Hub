class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int sz = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int a=0; a<sz - 3; a++){
            if(a && nums[a - 1] == nums[a]) continue;
            for(int b=a+1; b<sz - 2; b++){
                if(b > a + 1 && nums[b - 1] == nums[b]) continue;
                long long tot = (long long)nums[a] + nums[b], left = b + 1, right = sz - 1;
                while(left < right){
                    if(tot + nums[left] + nums[right] == target){
                        ans.push_back({nums[a], nums[b], nums[left], nums[right]});
                        left++, right--;
                        while(left < right && nums[left - 1] == nums[left]) left++;
                    }
                    else if(tot + nums[left] + nums[right] < target){
                        left++; while(left < right && nums[left - 1] == nums[left]) left++;
                    }
                    else{
                        right--; while(left < right && nums[right] == nums[right + 1]) right--;
                    }
                }
            }
        }
        return ans;
    }
};