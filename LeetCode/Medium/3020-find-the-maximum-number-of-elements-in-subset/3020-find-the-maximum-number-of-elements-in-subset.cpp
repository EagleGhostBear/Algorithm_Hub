class Solution {
public:
    long long powLong(int base, int t){
        long long ret = 1;
        while(t--) ret *= base;
        return ret;
    }
    int maximumLength(vector<int>& nums) {
        int ans = 1;
        map<long long, int> m;
        for(auto n : nums) m[n]++;
        for(auto n : m){
            if(n.first == 1){
                if(n.second % 2) ans = max(ans, n.second);
                else ans = max(ans, n.second - 1);
                continue;
            }
            int base = n.first, t = 1, cnt = 1;
            while(m.find(powLong(base, t)) != m.end()){ // 있다면
                if(m[powLong(base, t)] < 2) break;
                t*=2;
                if(m.find(powLong(base, t)) == m.end()) break;
                cnt++;
            }
            ans = max(ans, cnt * 2 - 1);
        }
        return ans;
    }
};
/*
2^1 2^2 2^4 2^8 2^16 // 2^32(범위초과)
*/