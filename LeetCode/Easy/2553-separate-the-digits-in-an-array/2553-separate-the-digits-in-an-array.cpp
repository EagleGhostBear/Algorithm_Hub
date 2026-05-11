class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto n : nums){
            string s = to_string(n);
            for(auto c : s) ans.push_back(c - '0');
        }
        return ans;
    }
};