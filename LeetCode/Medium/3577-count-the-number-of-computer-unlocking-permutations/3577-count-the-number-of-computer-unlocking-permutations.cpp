typedef long long ll;

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        for(int i=1; i<complexity.size(); i++){
            if(complexity[i] <= complexity[0]) return 0;
        }
        ll ans = 1, mod = 1e9 + 7;
        for(int i=2; i<complexity.size(); i++){
            ans = (ll)(ans * i) % mod;
        }
        return ans;
    }
};