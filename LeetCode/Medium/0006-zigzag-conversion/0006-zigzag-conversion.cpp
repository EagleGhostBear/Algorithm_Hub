class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> v(numRows);
        bool dir = false; // 아래, true : 위
        int row = 0;
        for(auto c : s){
            v[row] += c;
            if(dir){ if(--row == 0) dir = false; }
            else{ if(++row == numRows - 1) dir = true; }
        }
        string ans = "";
        for(auto ss : v) ans += ss;
        return ans;
    }
};