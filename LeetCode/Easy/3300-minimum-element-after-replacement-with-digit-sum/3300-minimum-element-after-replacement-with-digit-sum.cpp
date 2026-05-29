class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 100;
        for(int i=0; i<nums.size(); i++){
            int now = nums[i], val = 0;
            while(now){
                val += (now % 10);
                now /= 10;
            }
            ans = min(ans, val);
        }
        return ans;
    }
};