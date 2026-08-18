class Solution {
public:
    int maxProduct(int n) {
        map<int, int> m;
        while(n){
            m[n % 10]++;
            n /= 10;
        }
        vector<pair<int, int>> v;
        for(auto c : m) v.push_back({c.first, c.second});
        int ans = v.back().first;
        if(--v.back().second == 0) v.pop_back();
        ans *= v.back().first;
        return ans;
    }
};