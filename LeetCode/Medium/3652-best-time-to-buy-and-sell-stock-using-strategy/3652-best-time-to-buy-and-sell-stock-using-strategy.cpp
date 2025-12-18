typedef long long ll;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        vector<ll> preSum(prices.size(), 0);
        for(int i=0; i<prices.size(); i++){
            if(i) preSum[i] = preSum[i - 1];
            preSum[i] += (prices[i] * strategy[i]);
        }
        ll ans = preSum.back();

        ll slide = 0, leftVal = 0, rightVal = preSum.back() - preSum[k - 1];
        for(int i=k/2; i<k; i++) slide += prices[i];
        ans = max(ans, leftVal + rightVal + slide);
        int leftIdx = 1;

        for(int i=k; i<prices.size(); i++){
            leftVal = preSum[leftIdx - 1];
            rightVal = (preSum.back() - preSum[i]);
            // 이동시 1. slide 가운데값 빼기, 2. slide 추가된값 더하기
            slide -= prices[(leftIdx + i) / 2];
            slide += prices[i];
            leftIdx++;
            ans = max(ans, leftVal + rightVal + slide);
        }
        return ans;
    }
};