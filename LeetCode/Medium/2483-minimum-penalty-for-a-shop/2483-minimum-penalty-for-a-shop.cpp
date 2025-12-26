class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> dp(customers.size() + 1, 0); // dp[i시간 폐점시] = 최소벌점
        
        int yCnt = 0, nCnt = 0;
        for(auto c : customers) if(c == 'N') nCnt++;
        dp[customers.size()] = nCnt;
        pair<int, int> ans = {nCnt, customers.size()}; // 벌점, 폐점시간

        for(int i=customers.size() - 1; i>-1; i--){
            // (<)i이전의 N개수 + i(<=) 이후 Y개수
            if(customers[i] == 'Y') yCnt++;
            else nCnt--;
            dp[i] = nCnt + yCnt;

            if(dp[i] == ans.first) ans.second = min(ans.second, i);
            else if(dp[i] < ans.first) ans = {dp[i], i};
        }
        return ans.second;
    }
};