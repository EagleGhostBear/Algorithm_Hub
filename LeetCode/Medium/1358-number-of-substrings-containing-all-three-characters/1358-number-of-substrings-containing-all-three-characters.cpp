class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0, sz = s.size();
        vector<vector<int>> alp(3, vector<int>());
        for(int i=0; i<sz; i++) alp[s[i] - 'a'].push_back(i);
        if(alp[0].size() == 0 || (alp[1].size() == 0 || alp[2].size() == 0)) return 0;
        vector<int> idx(3, 0); // a, b, c의 idx 위치
        for(int i=0; i<sz - 2; i++){ // 시작 idx 위치
            for(int j=0; j<3; j++) while(idx[j] < alp[j].size() && i > alp[j][idx[j]]) idx[j]++;
            if(idx[0] >= alp[0].size() || (idx[1] >= alp[1].size() || idx[2] >= alp[2].size())) break;
            int maxIdx = 0;
            for(int j=0; j<3; j++) maxIdx = max(maxIdx, alp[j][idx[j]]);
            ans += sz - maxIdx;
        }
        return ans;
    }
};