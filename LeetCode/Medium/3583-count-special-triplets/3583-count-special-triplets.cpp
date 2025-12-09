typedef long long ll;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int ans = 0, rem = 1e9 + 7;
        unordered_map<int, vector<int>> um;
        for(int i=0; i<nums.size(); i++) um[nums[i]].push_back(i);
        for(auto c : um){
            int jVal = c.first;
            int ikVal = c.first * 2;
            if(um.find(ikVal) == um.end()) continue;
            int sz = um[ikVal].size();
            if(c.first == 0){
                for(ll i=0; i<sz; i++){
                    ll tmp = i * (sz - i - 1) % rem;
                    ans = (ans + tmp) % rem;
                }
                continue;
            }
            vector<int> cnt(c.second.size(), 0); // j 기준으로 더 작은게 몇개인가
            int idx = 0;
            for(int i=0; i<c.second.size(); i++){
                if(i) cnt[i] = cnt[i-1];
                int now = c.second[i];
                for(; idx<sz; idx++){
                    if(um[ikVal][idx] < now) cnt[i]++;
                    else break;
                }
                ans = (ans + cnt[i] * (sz - cnt[i])) % rem;
            }
        }
        return ans;
    }
};