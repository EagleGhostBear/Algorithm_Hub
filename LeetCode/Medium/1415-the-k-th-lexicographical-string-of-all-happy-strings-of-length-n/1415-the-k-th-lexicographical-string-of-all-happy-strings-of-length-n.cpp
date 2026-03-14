class Solution {
public:
    string getHappyString(int n, int k) {
        string ans = "";
        int cnt = 3 * (1 << (n - 1)); //1536
        if(k > cnt) return ans;
        vector<int> v(n);
        v.back() = 1;
        for(int i=v.size() - 2; i>-1; i--) v[i] = v[i + 1] * 2;
        // 첫번째자리 3가지 가능성
        for(int j=0; j<3; j++) if(k <= v[0] * (j + 1)){
            k -= v[0] * j;
            ans += 'a' + j;
            break;
        }
        // 그이외 2가지 가능성
        for(int i=1; i<n; i++){
            for(int j=0; j<2; j++) if(k <= v[i] * (j + 1)){
                k -= v[i] * j;
                if(ans.back() == 'a' || (ans.back() == 'b' && j == 1)) ans += 'a' + j + 1;
                else ans += 'a' + j;
                break;
            }
        }
        return ans;
    }
};