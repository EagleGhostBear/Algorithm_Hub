class Solution {
public:
    bool check(vector<int>& nums) {
        int prev = nums.front();
        pair<int, int> cnt;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] - prev >= 0) cnt.first++;
            else cnt.second++;
            prev = nums[i];
        }
        if(nums.front() - prev >= 0) cnt.first++;
        else cnt.second++;
        if(cnt.second == 0 || cnt.second == 1) return true;
        return false;
    }
};