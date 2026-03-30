class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<vector<int>> alp1(2, vector<int>(26, 0));
        vector<vector<int>> alp2(2, vector<int>(26, 0));
        for(int i=0; i<s1.size(); i++){
            int val = i % 2;
            alp1[val][s1[i] - 'a']++;
            alp2[val][s2[i] - 'a']++;
        }
        for(int i=0; i<26; i++) if(alp1[0][i] != alp2[0][i] || alp1[1][i] != alp2[1][i]) return false;
        return true;
    }
};