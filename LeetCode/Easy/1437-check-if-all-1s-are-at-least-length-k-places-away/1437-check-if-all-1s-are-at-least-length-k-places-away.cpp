class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int len = 1e9;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                if(k > len) return false;
                len = 0;
            }
            else len++;
        }
        return true;
    }
};