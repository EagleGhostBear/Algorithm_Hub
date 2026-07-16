class Solution {
public:
    long long gcd(long long a, long long b){
        while(b){
            long long tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        long long ans = 0, maxVal = 0;
        vector<int> v(nums.size());
        for(int i=0; i<nums.size(); i++){
            maxVal = max(maxVal, (long long)nums[i]);
            v[i] = gcd(nums[i], maxVal);
        }
        sort(v.begin(), v.end());
        for(int i=0; i<v.size()/2; i++) ans += gcd(v[i], v[v.size() - 1 - i]);
        return ans;
    }
};