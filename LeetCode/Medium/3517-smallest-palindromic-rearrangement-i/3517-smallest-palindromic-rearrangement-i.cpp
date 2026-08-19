class Solution {
public:
    string smallestPalindrome(string s) {
        map<int, int> m;
        for(auto c : s) m[c - 'a']++;
        string ans = "";
        int mid = 27;
        for(auto c : m){
            if(c.second % 2){ mid = c.first; c.second--; }
            c.second /= 2;
            while(c.second--) ans += c.first + 'a';
            
        }
        int idx = ans.size() - 1;
        if(mid < 27) ans += mid + 'a';
        for(int i=idx; i>-1; i--) ans += ans[i];
        return ans;
    }
};