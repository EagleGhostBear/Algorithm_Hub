typedef long long ll;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        ll ans = 0;
        vector<vector<ll>> dp(prices.size(), vector<ll>(k + 1, 0)); // dp[날짜][거래회수] = 총 이익
        for(int t=1; t<=k; t++){
            ll maxNormal = -1e18, maxShort = -1e18;
            for(int now=0; now<prices.size(); now++){
                // 안할때
                if(now) dp[now][t] = dp[now - 1][t];

                // 일반거래
                dp[now][t] = max(dp[now][t], prices[now] + maxNormal);
                // 공매도
                dp[now][t] = max(dp[now][t], -prices[now] + maxShort);

                // now=0 도 고려해야하기 때문에 dp[now-1][t-1] 를 먼저 계산
                ll prevProfit = (now ? dp[now - 1][t - 1] : 0);
                // 거래 or 공매도 우항 최대값 계산
                maxNormal = max(maxNormal, prevProfit - prices[now]);
                maxShort = max(maxShort, prevProfit + prices[now]);
            }
        }
        for(int i=0; i<=k; i++) ans = max(ans, dp.back()[i]);
        return ans;
    }
};
/*
1. 일반  거래: prices[i] + (dp[j-1][k-1] - prices[j])
2. 공매도거래: -prices[i] + (dp[j-1][k-1] + prices[j])
따라서 오른쪽 항은 i의 영향을 받지 않으므로 오른쪽항의 최대값만 기억하고 있으면 된다.
*/