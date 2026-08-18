class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ans = 0, sz = s.size();
        vector<pair<int, int>> v;
        if(s[0] == '0') v.push_back({0, 1});
        else v.push_back({1, 1});
        for(int i=1; i<sz; i++){
            if(s[i] == s[i - 1]) v.back().second++;
            else{
                if(s[i] == '1' && s[i - 1] == '0') v.push_back({2, 1});
                else v.push_back({s[i] - '0', 1});

                if(v.back().first == 0 && v[v.size() - 2].first == 2) v[v.size() - 2].first = 3;
            }
        }
        int maxVal = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i].first != 0) ans += v[i].second; // 순수 1의 개수
            if(v[i].first == 3){ // 1반전 0반전 시킨 길이
                maxVal = max(maxVal, v[i - 1].second + v[i + 1].second);
            }
        }
        ans += maxVal;
        return ans;
    }
};