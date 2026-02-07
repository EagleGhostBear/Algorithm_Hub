class Solution {
public:
    int minimumDeletions(string s) {
        vector<pair<int, int>> cnt(s.size(), pair<int, int>({0, 0}));
        for(int i=0; i<s.size(); i++){
            if(i) cnt[i] = cnt[i - 1];
            if(s[i] == 'a') cnt[i].first++;
            else if(s[i] == 'b') cnt[i].second++;
        }
        int ans = min(cnt.back().first, cnt.back().second);
        for(int i=0; i<s.size(); i++){ // 해당 idx 뒤를 기준
            int left = cnt[i].second;
            int right = cnt.back().first - cnt[i].first;
            ans = min(ans, left + right);
        }
        return ans;
    }
};
/*
특정 idx를 기준으로 앞은 전부 a, 뒤는 전부 b 로 해서 연산
*/