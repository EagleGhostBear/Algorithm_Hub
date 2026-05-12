class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int ans = 1, l = 0;
        vector<int> alp(127, 0);
        alp[s[0]]++;
        for(int r=1; r<s.size(); r++){
            if(++alp[s[r]] == 1){
                ans = max(ans, r - l + 1);
                continue;
            }
            while(s[l] != s[r]){alp[s[l]]--; l++;}
            alp[s[l]]--; l++;
        }
        return ans;
    }
};