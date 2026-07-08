class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        vector<int> ans, len(s.size() + 1, 0), preSum(s.size() + 1, 0);
        vector<long long> preMod(s.size() + 1, 0), preGap(1e5 + 1);
        len[0] = 0, preSum[0] = 0, preMod[0] = 0, preGap[0] = 1;
        for(int i=1; i<=1e5; i++) preGap[i] = preGap[i - 1] * 10 % mod;
        for(int i=0; i<s.size(); i++){
                len[i + 1] = len[i];
                preSum[i + 1] = preSum[i];
                preMod[i + 1] = preMod[i];
            if(s[i] != '0'){
                int num = s[i] - '0';
                len[i + 1]++;
                preSum[i + 1] += num;
                preMod[i + 1] = (preMod[i + 1] * 10 + num) % mod;
            }
        }
        for(int i=0; i<queries.size(); i++){
            int from = queries[i][0] + 1, to = queries[i][1] + 1;
            int totSum = preSum[to] - preSum[from - 1];
            int gap = len[to] - len[from - 1];
            long long tmp = preMod[from - 1] * preGap[gap] % mod;
            long long val = (preMod[to] - tmp + mod) * totSum % mod;
            ans.push_back(val);
        }
        return ans;
    }
};