class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans = 0;
        sort(costs.begin(), costs.end());
        for(auto c : costs){
            if(c > coins) break;
            else{ ans++; coins -= c; }
        }
        return ans;
    }
};