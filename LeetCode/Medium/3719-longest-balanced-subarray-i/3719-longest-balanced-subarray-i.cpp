class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        for(int len=nums.size(); len>=2; len--){
            unordered_map<int, int> even, odd;
            for(int i=0; i<len; i++){
                if(nums[i] % 2) odd[nums[i]]++;
                else even[nums[i]]++;
            }
            if(odd.size() == even.size()) return len;
            for(int i=len; i<nums.size(); i++){
                if(nums[i] % 2) odd[nums[i]]++;
                else even[nums[i]]++;
                int prev = i - len;
                if(nums[prev] % 2){
                    if(--odd[nums[prev]] == 0) odd.erase(nums[prev]);
                }
                else{
                    if(--even[nums[prev]] == 0) even.erase(nums[prev]);
                }
                if(odd.size() == even.size()) return len;
            }
        }
        return ans;
    }
};