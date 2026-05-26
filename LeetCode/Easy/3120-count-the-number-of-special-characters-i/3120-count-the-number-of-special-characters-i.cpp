class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        vector<bool> lower(26), upper(26);
        for(int i=0; i<word.size(); i++){
            if('a' <= word[i] && word[i] <= 'z') lower[word[i] - 'a'] = true;
            else upper[word[i] - 'A'] = true;
        }
        for(int i=0; i<26; i++) if(lower[i] && upper[i]) ans++;
        return ans;
    }
};