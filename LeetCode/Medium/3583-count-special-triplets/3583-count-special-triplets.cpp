typedef long long ll;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int ans = 0, rem = 1e9 + 7;
        vector<vector<int>> v(1e5 + 1, vector<int>());
        for(int i=0; i<nums.size(); i++) v[nums[i]].push_back(i);
        if(v[0].size()){
            int sz = v[0].size();
            for(ll i=0; i<sz; i++){
                ll tmp = i * (sz - i - 1) % rem;
                ans = (ans + tmp) % rem;
            }
        }
        for(int i=1; i<v.size(); i++){
            int jVal = i;
            int ikVal = i * 2;
            if(ikVal > 1e5 || v[ikVal].size() < 2) continue;
            int sz = v[ikVal].size();

            vector<int> cnt(v[jVal].size(), 0); // j 기준으로 더 작은게 몇개인가
            int idx = 0;
            for(int j=0; j<v[jVal].size(); j++){
                if(j) cnt[j] = cnt[j-1];
                int now = v[jVal][j];
                for(; idx<sz; idx++){
                    if(v[ikVal][idx] < now) cnt[j]++;
                    else break;
                }
                ans = (ans + cnt[j] * (sz - cnt[j])) % rem;
            }
        }
        return ans;
    }
};