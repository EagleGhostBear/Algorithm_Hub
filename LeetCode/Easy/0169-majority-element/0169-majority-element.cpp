class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = -1, cnt = 0;
        unordered_map<int, int> um;
        for(auto n : nums) if(++um[n] > cnt){
            cnt = um[n];
            ans = n;
        }
        return ans;
    }
};