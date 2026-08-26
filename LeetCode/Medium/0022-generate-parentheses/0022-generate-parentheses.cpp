class Solution {
public:
    vector<string> ans;
    
    void solve(int a, int b, string s){
        if(a == 0 && b == 0){ ans.push_back(s); return; }
        if(a < b && b){ // )을 추가하는 경우
            solve(a, b - 1, s + ')');
        }
        if(a) solve(a - 1, b, s + '('); // (을 추가하는 경우
        return;
    }
    vector<string> generateParenthesis(int n) {
        solve(n, n, "");
        return ans;
    }
};