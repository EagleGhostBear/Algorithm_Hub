class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> alp(26);
        for(auto c : s) alp[c - 'a']++;
        string ans = "";
        int mid = 27;
        for(int i=0; i<26; i++){
            if(alp[i] % 2){ mid = i; alp[i]--; }
            alp[i] /= 2;
            while(alp[i]--) ans += i + 'a';
        }
        int idx = ans.size() - 1;
        if(mid < 27) ans += mid + 'a';
        for(int i=idx; i>-1; i--) ans += ans[i];
        return ans;
    }
};