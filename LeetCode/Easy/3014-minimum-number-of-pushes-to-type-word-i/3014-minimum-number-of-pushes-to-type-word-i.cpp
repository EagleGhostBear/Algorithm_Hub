class Solution {
public:
    int minimumPushes(string word) {
        vector<int> alp(26);
        for(auto c : word) alp[c - 'a']++;
        sort(alp.begin(), alp.end(), greater<int>());
        int ans = 0, cnt = 0;
        for(auto c : alp){
            if(c == 0) break;
            int now = (cnt++ / 8) + 1;
            ans += now * c;
        }
        return ans;
    }
};
/*
8개
26
*/