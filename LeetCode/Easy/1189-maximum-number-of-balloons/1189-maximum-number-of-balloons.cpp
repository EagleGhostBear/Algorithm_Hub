class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(26);
        for(auto c : text) cnt[c - 'a']++;
        int ans = cnt[0];
        ans = min(ans, cnt['b' - 'a']);
        ans = min(ans, cnt['l' - 'a'] / 2);
        ans = min(ans, cnt['o' - 'a'] / 2);
        ans = min(ans, cnt['n' - 'a']);
        return ans;
    }
};