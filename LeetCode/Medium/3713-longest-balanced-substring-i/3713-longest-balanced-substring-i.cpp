class Solution {
public:
    bool is_balanced(int sIdx, int eIdx, vector<vector<int>>& prefixSum){
        int val = 0;
        for(int i=0; i<26; i++){
            int now = (sIdx >= 0 ? prefixSum[eIdx][i] - prefixSum[sIdx][i] : prefixSum[eIdx][i]);
            if(now == 0) continue;
            if(now && val == 0) val = now;
            if(now != val) return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        vector<vector<int>> prefixSum(s.size(), vector<int>(26, 0));
        for(int i=0; i<s.size(); i++){
            if(i) prefixSum[i] = prefixSum[i - 1];
            prefixSum[i][s[i] - 'a']++;
        }
        for(int len=s.size(); len>1; len--){
            int sIdx, eIdx;
            for(int i=len - 1; i<s.size(); i++){
                eIdx = i, sIdx = eIdx - len + 1;
                if(is_balanced(sIdx - 1, eIdx, prefixSum)) return len;
            }
        }
        return 1;
    }
};
/*
종류 26가지
투포인터?

글자별로 idx를 수집?
시작 idx를 기준으로 짝수idx - 그다음 idx 까지를 탐색

특정 알파벳의 개수를 기준으로 나머지를 확인?
*/