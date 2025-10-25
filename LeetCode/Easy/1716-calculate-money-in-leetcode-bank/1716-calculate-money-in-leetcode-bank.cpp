class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        for(int i=0; i<n/7; i++) ans += (28 + 7 * i);
        int s = n/7 + 1;
        for(int i=0; i<n%7; i++) ans += (s + i);
        return ans;
    }
};