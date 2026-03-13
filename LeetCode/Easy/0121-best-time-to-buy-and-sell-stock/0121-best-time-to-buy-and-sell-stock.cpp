class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, prev = 1e5;
        for(int i=0; i<prices.size(); i++){
            ans = max(ans, prices[i] - prev);
            prev = min(prev, prices[i]);
        }
        return ans;
    }
};