class Solution {
public:
    bool isGood(vector<int>& nums) {
        vector<int> v(nums.size());
        for(auto n : nums){
            if(n >= nums.size()) return false;
            v[n]++;
        }
        for(auto n : v) cout << n << " ";
        for(int i=1; i<v.size() - 1; i++) if(v[i] != 1) return false;
        if(v.back() != 2) return false;
        return true;
    }
};