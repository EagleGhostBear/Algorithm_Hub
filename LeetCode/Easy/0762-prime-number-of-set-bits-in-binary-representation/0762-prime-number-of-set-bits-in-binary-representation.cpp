class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        vector<bool> v(right + 1, 0);
        v[0] = true, v[1] = true;
        for(int i=2; i<=right; i++){
            if(v[i]) continue;
            for(int j=2; i*j<=right; j++) v[i * j] = true;
        }
        vector<int> cnt(right + 1);
        cnt[0] = 0, cnt[1] = 1;
        for(int i=2; i<=right; i<<=1){
            for(int j=0; j<i; j++){
                if(i + j > right) break;
                cnt[i + j] = cnt[j] + 1;
                if(left <= i + j && !v[cnt[i + j]]) ans++;
            }
        }
        return ans;
    }
};