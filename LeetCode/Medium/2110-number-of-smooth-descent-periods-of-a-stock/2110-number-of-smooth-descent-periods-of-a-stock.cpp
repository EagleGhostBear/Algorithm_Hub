class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int prev = -1, cnt = 0;
        for(int i=0; i<prices.size(); i++){
            if(prev - prices[i] == 1) cnt++;
            else{
                ans += (long long) cnt * (cnt + 1) / 2;
                cnt = 1;
            }
            prev = prices[i];
        }
        ans += (long long) cnt * (cnt + 1) / 2;
        return ans;
    }
};