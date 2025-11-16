class Solution {
public:
    int numSub(string s) {
        int div = 1e9 + 7;
        vector<pair<int, int>> v;
        v.push_back({0, 0});
        for(int i=1; i<=1e5; i++){
            v.push_back({(v[i - 1].first + i) % div, 0});
        }

        int cnt = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0'){
                v[cnt].second++;
                cnt = 0;
            }
            else cnt++;
        }
        v[cnt].second++;
        int ans = 0;
        for(int i=1; i<=1e5; i++){
            int val = (v[i].first * v[i].second) % div;
            ans = (ans + val) % div;
        }
        return ans;
    }
};