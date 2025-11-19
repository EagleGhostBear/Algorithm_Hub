class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<bool> num(2001, false);
        for(auto n : nums) num[n] = true;
        while(num[original]) original *= 2;
        return original;
    }
};