class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int sz = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        unordered_map<int, bool> ans;
        unordered_map<int, bool> um;
        for(int a=0; a<sz; a++){
            for(int b=a; b<sz; b++){
                int val = nums[a] ^ nums[b];
                if(um[val]) continue;
                um[val] = true;
                for(int c=b; c<sz; c++) ans[val ^ nums[c]] = true;
            }
        }
        return ans.size();
    }
};