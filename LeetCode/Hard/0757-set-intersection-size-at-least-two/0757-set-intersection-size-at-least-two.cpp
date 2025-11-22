class Solution {
public:
    struct compare{
        bool operator()(pair<int, int> left, pair<int, int> right){
            if(left.second < right.second) return true;
            if(left.second > right.second) return false;

            if(left.first < right.first) return true;
            if(left.first > right.first) return false;
            return false;
        }
    };
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int ans = 2;
        vector<pair<int, int>> v;
        for(int i=0; i<intervals.size(); i++){
            v.push_back({intervals[i][0], intervals[i][1]});
        }
        sort(v.begin(), v.end(), compare());

        deque<int> dq;
        for(int i=-1; i<1; i++) dq.push_back(v[0].second + i);
        for(int i=1; i<v.size(); i++){
            while(dq.size() && (dq.front() < v[i].first)) dq.pop_front();
            if(dq.size() < 2){
                for(int j=v[i].second; j>=v[i].second - 1; j--){
                    if(dq.size() >= 2) break;
                    if(dq.size() && dq.back() == j) continue;

                    dq.push_back(j);
                    sort(dq.begin(), dq.end());
                    ans++;
                }
            }
        }
        return ans;
    }
};
/*
예외 상황 [1,7][2,3] -> 6,7을 넘으면 안되고 2,3을 넣어야함 어떻게 구별할 것인가?
빨리 끝나는 순으로 정렬해 가장 큰수 2개씩만 넣으면 되는게 아닌가?
*/