class Solution {
public:
    string smallestSubsequence(string s) {
        string ans = "";
        int sz = s.size(), totCnt = 0, left = 0;
        unordered_map<char, bool> alp; // 윈도우내부 알파벳 개수 카운팅
        for(auto c : s) alp[c] = true;
        totCnt = alp.size();
        alp.clear();

        while(totCnt){
            int right = sz - 1;
            unordered_map<char, bool> cnt;
            for(; right>=left; right--){
                if(alp[s[right]]) continue; // 이미 사용된 알파벳
                cnt[s[right]] = true;
                if(cnt.size() == totCnt) break;
            }
            int idx = -1;
            for(int i=left; i<=right; i++){
                if(alp[s[i]]) continue;
                if(idx < 0 || s[i] < s[idx]) idx = i;
            }
            // 해당 알파벳 사용
            ans += s[idx];
            alp[s[idx]] = true;
            left = idx + 1;
            totCnt--;
        }
        return ans;
    }
};
/*
슬라이딩 윈도우
*/