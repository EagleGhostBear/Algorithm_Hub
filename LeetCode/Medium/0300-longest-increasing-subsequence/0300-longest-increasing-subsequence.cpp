class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(int i=0; i<nums.size(); i++){
            if(lis.empty() || lis.back() < nums[i]) lis.push_back(nums[i]);
            else{
                int left = 0, right = lis.size() - 1;
                int mid = 0;
                while(left <= right){
                    mid = (left + right) / 2;
                    if(lis[mid] == nums[i]) break;
                    else if(lis[mid] < nums[i]) left = mid + 1;
                    else right = mid - 1;
                }
                if(lis[mid] < nums[i]) lis[mid + 1] = nums[i];
                else lis[mid] = nums[i];
            }
        }
        return lis.size();
    }
};