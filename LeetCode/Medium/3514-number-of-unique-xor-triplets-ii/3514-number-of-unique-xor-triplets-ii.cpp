class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int sz = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        vector<bool> ans(2049);
        vector<bool> chk(2049);
        for(int a=0; a<sz; a++){
            for(int b=a; b<sz; b++){
                int val = nums[a] ^ nums[b];
                if(chk[val]) continue;
                chk[val] = true;
                for(int c=b; c<sz; c++) ans[val ^ nums[c]] = true;
            }
        }
        int cnt = 0;
        for(auto c : ans) if(c) cnt++;
        return cnt;
    }
};