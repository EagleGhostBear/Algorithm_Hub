class Solution {
public:
    struct compare{
        bool operator()(vector<int> left, vector<int> right){
            if(left[0] < right[0]) return true;
            if(left[0] > right[0]) return false;
            if(left[1] > right[1]) return true;
            if(left[1] < right[1]) return false;
            return false;
        }
    };
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = 0, prev = -1;
        sort(intervals.begin(), intervals.end(), compare());
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][1] <= prev) continue;
            ans++;
            prev = intervals[i][1];
        }
        return ans;
    }
};