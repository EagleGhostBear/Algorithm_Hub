class Solution {
public:
    int ans = 0;
    vector<pair<int, int>> v;
    void solve(int idx, int cnt, int cnt0, int cnt1, int& m, int& n){
        ans = max(ans, cnt);

        for(int i=idx+1; i<v.size(); i++){
            if(cnt0 + v[i].first > m || cnt1 + v[i].second > n) continue;
            solve(i, cnt + 1, cnt0 + v[i].first, cnt1 + v[i].second, m, n);
        }
        return;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        for(int i=0; i<strs.size(); i++){
            pair<int, int> now = {0, 0};
            for(int j=0; j<strs[i].size(); j++){
                if(strs[i][j] == '0') now.first++;
                else now.second++;
            }
            if(now.first <= m && now.second <= n) v.push_back(now);
        }
        sort(v.begin(), v.end());
        solve(-1, 0, 0, 0, m, n);
        return ans;
    }
};