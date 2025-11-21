class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        vector<vector<int>> alp(26, vector<int>());
        for(int i=0; i<s.size(); i++){
            alp[s[i] - 'a'].push_back(i);
        }
        for(int i=0; i<26; i++){
            if(alp[i].size() > 1){
                int ft = alp[i].front();
                int bk = alp[i].back();
                for(int j=0; j<26; j++){
                    if(i == j && alp[i].size() > 2) ans++;
                    else{
                        for(int k=0; k<alp[j].size(); k++){
                            if(ft < alp[j][k] && alp[j][k] < bk){
                                ans++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
/*
10만자리
같은 문자들을 찾
*/