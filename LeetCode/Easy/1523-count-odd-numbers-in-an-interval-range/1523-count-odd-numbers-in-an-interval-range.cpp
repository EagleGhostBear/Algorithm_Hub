class Solution {
public:
    int countOdds(int low, int high) {
        if(low) low -= 1;
        int ans = (high % 2 ? high / 2 + 1 : high / 2);
        ans -= (low % 2 ? low / 2 + 1 : low / 2);
        return ans;
    }
};