class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int sz = max(a.size(), b.size());
        int cnt = 0;
        for(int i=0; i<sz; i++){
            int val = cnt;
            cnt = 0;
            if(i < a.size()) val += (a[a.size() - 1 - i] - '0');
            if(i < b.size()) val += (b[b.size() - 1 - i] - '0');
            if(val > 1){cnt = 1; val -= 2;}
            ans += to_string(val);
        }
        if(cnt) ans += to_string(cnt);
        for(int i=0; i<ans.size()/2; i++){
            char tmp = ans[i];
            ans[i] = ans[ans.size() - 1 - i];
            ans[ans.size() - 1 - i] = tmp;
        }
        return ans;
    }
};