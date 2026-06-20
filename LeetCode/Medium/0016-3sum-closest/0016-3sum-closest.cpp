class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 1e5, sz = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<sz; i++){
            int left = i + 1, right = sz - 1;
            while(left < right){
                int tot = nums[i] + nums[left] + nums[right];
                if(tot == target) return target;
                else{
                    if(abs(target - ans) > abs(target - tot)) ans = tot;
                    if(tot < target) left++;
                    else right--;
                }
                
            }
        }
        return ans;
    }
};