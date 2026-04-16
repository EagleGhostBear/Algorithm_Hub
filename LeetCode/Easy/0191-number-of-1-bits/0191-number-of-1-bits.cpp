class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0, val = pow(2, 30);
        while(n){
            if(n >= val){
                n -= val;
                ans++;
            }
            val /= 2;
        }
        return ans;
    }
};