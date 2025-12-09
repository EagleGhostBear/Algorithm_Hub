typedef long long ll;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        ll ans = 0, rem = 1e9 + 7;
        vector<int> prev(1e5 + 1, 0);
        vector<int> total(1e5 + 1, 0);
        for(int i=0; i<nums.size(); i++) total[nums[i]]++;
        for(int i=0; i<nums.size(); i++){
            int val = nums[i], val2 = (val << 1);
            if(val2 <= 1e5) ans += (ll)prev[val2] * (total[val2] - prev[val2] -(val == 0));
            prev[val]++;
        }
        return ans % rem;
    }
};