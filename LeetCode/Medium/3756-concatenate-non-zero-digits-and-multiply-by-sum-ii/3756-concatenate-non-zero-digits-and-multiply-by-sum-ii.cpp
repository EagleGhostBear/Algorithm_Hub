class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        vector<int> ans, len(s.size()), preSum(s.size(), 0);
        vector<long long> preMod(s.size(), 0), preGap(1e5 + 1);
        preGap[0] = 1;
        for(int i=1; i<=1e5; i++) preGap[i] = preGap[i - 1] * 10 % mod;
        for(int i=0; i<s.size(); i++){
            if(i){
                len[i] = len[i - 1];
                preSum[i] = preSum[i - 1];
                preMod[i] = preMod[i - 1];
            }
            if(s[i] != '0'){
                int num = s[i] - '0';
                len[i]++;
                preSum[i] += num;
                preMod[i] = (preMod[i] * 10 + num) % mod;
            }
        }
        for(int i=0; i<queries.size(); i++){
            int from = queries[i][0], to = queries[i][1];
            int totSum = (from ? preSum[to] - preSum[from - 1] : preSum[to]);
            int gap = len[to] - (from ? len[from - 1] : 0);
            long long tmp = (from ? preMod[from - 1] : 0) * preGap[gap] % mod;
            long long val = (preMod[to] - tmp + mod) * totSum % mod;
            ans.push_back(val);
        }
        return ans;
    }
};