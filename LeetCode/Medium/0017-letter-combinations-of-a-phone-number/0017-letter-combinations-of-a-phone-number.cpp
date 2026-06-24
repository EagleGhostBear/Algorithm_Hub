class Solution {
public:
    void solve(vector<string>& ans, vector<vector<char>>& v, string& digits, string tot, int idx){
        if(idx == digits.size()){ ans.push_back(tot); return; }
        int num = digits[idx] - '0';
        for(auto c : v[num]) solve(ans, v, digits, tot + c, idx + 1);
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<vector<char>> v = {{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        solve(ans, v, digits, "", 0);
        return ans;
    }
};