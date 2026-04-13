class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        for(int i=0; i<nums.size(); i++){
            if(0 <= start - i && nums[start - i] == target) return i;
            if(start + i < nums.size() && nums[start + i] == target) return i;
        }
        return 0;
    }
};