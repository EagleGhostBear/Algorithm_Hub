class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        pair<int, int> prev = {points[0][0], points[0][1]};
        for(int i=1; i<points.size(); i++){
            int rowGap = abs(points[i][0] - prev.first);
            int colGap = abs(points[i][1] - prev.second);
            ans += max(rowGap, colGap);
            prev = {points[i][0], points[i][1]};
        }
        return ans;
    }
};