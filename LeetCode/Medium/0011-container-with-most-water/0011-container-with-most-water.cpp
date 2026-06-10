class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        vector<int> minH(1e4 + 1, 1e6);
        vector<int> maxH(1e4 + 1, -1e6);
        for(int i=0; i<height.size(); i++){ // 1e5
            minH[height[i]] = min(minH[height[i]], i);
            maxH[height[i]] = max(maxH[height[i]], i);
        }
        for(int l=1e4; l>0; l--){ // 1e4 * 1e4
            if(maxH[l] == -1e6) continue;
            for(int r=l; r>0; r--){
                if(minH[r] == 1e6) continue;
                ans = max(ans, min(l,r) * abs(maxH[l] - minH[r]));
                ans = max(ans, min(l,r) * abs(minH[l] - maxH[r]));
            }
        }
        return ans;
    }
};