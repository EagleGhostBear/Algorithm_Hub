class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> v(10001);
        for(auto c : nums) v[c]++;
        int ans = 0;
        for(int i=0; i<v.size(); i++) if(v[i] == n) {ans=i; break;}
        return ans;
    }
};