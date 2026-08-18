class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ans = 0, sz = s.size();
        vector<int> zero;
        int cnt = 0;
        for(int i=0; i<sz; i++){
            if(s[i] == '0') cnt++;
            else{
                ans++;
                if(cnt){
                    zero.push_back(cnt);
                    cnt = 0;
                }
            }
        }
        if(cnt) zero.push_back(cnt);
        int maxVal = 0;
        if(zero.size() > 1){
            for(int i=0; i<zero.size() - 1; i++) maxVal = max(maxVal, zero[i] + zero[i + 1]);
        }
        return ans + maxVal;
    }
};