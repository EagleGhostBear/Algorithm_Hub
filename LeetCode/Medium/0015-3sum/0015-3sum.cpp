class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<bool> visited(2e5 + 1);
        for(int i=0; i<nums.size() - 2; i++){
            if(visited[nums[i] + 1e5]) continue;
            visited[nums[i] + 1e5] = true;
            vector<bool> visited2(2e5 + 1);
            for(int j=i+1; j<nums.size() - 1; j++){
                if(visited2[nums[j] + 1e5]) continue;
                visited2[nums[j] + 1e5] = true;
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