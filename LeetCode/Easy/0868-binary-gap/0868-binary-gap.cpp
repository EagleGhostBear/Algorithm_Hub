class Solution {
public:
    int binaryGap(int n) {
        int ans = 0, nowIdx = 0, prevIdx = -1;
        for(int i=1; i<=n; i<<=1){
            if(n & i){
                if(prevIdx >= 0) ans = max(ans, nowIdx - prevIdx);
                prevIdx = nowIdx;
            }
            nowIdx++;
        }
        return ans;
    }
};