class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        vector<pair<int, int>> h;
        for(int i=0; i<height.size(); i++){ // 1e5
            for(int j=0; j<h.size(); j++){
                ans = max(ans, (i - h[j].first) * min(height[i], h[j].second));
            }
            if(h.empty() || h.back().second < height[i]) h.push_back({i, height[i]});
        }
        return ans;
    }
};