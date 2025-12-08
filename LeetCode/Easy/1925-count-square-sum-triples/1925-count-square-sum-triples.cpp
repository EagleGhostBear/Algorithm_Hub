class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int c=1; c<=n; c++){
            for(int a=1; a<c; a++){
                double val = sqrt((c + a) * (c - a));
                if(val == int(val)) ans++;
            }
        }
        return ans;
    }
};