class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        pair<int, int> num = {-1e9, 0}; // val, cnt
        for(int i=0; i<nums.size(); i++){
            if(num.first < nums[i] - k){num.first = nums[i] - k + 1, num.second++;}
            else if(num.first > nums[i] + k) continue;
            else{num.first++; num.second++;}
        }
        return num.second;
    }
};