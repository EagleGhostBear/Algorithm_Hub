class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int sz = piles.size();
        vector<vector<int>> dp(sz, vector<int>(sz));
        for(int i=0; i<sz; i++) dp[i][i] = piles[i];
        for(int len=2; len<=sz; len++){
            for(int l=0; l+len-1<sz; l++){
                int r = l + len - 1;
                dp[l][r] = max(piles[l] - dp[l + 1][r], piles[r] - dp[l][r - 1]);
            }
        }
        if(dp[0][sz - 1] > 0) return true;
        return false;
    }
};