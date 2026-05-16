class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "", ns = "#";
        int c = -1, r = -1;
        for(int i=0; i<s.size(); i++) ns = ns + s[i] + '#';
        vector<int> dp(ns.size());
        for(int i=0; i<ns.size(); i++){
            int mirror = 2 * c - i;
            if(i <= r && dp[mirror]) dp[i] = min(r - i, dp[mirror]); // r범위밖은 보장되어있지 않다.
            int minVal = min(i, (int)ns.size() - i - 1);
            for(int j=dp[i] + 1; j<=minVal; j++){
                if(ns[i - j] != ns[i + j]) break;
                dp[i]++;
            }
            if(i + dp[i] > r) {r = i + dp[i]; c = i;}
        }
        pair<int, int> maxVal = {0, 0};
        for(int i=0; i<dp.size(); i++) if(maxVal.second < dp[i]) maxVal = {i, dp[i]};
        ans = s.substr((maxVal.first - maxVal.second) / 2, maxVal.second);
        return ans;
    }
};
/*
마나커 알고리즘 풀이
*/