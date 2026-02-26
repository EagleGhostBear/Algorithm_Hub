class Solution {
public:
    int numSteps(string s) {
        int ans = 0, up = 0;
        for(int i=s.size() - 1; i>-1; i--){
            if(i == 0 && up == 0) break;
            int now = s[i] - '0' + up; up = 0;
            if(now == 2) up++, now = 0;
            else if(now == 1) ans++, up++;
            ans++;
        }
        return ans;
    }
};