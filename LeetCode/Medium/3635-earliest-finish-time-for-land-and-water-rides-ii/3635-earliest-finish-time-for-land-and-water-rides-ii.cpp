class Solution {
public:
    vector<pair<int, int>> sortTime(vector<int>& startTime, vector<int>& duration){
        vector<pair<int, int>> ret;
        unordered_map<int, int> um;
        for(int i=0; i<startTime.size(); i++){
            int val = um[startTime[i]];
            if(val) um[startTime[i]] = min(val, duration[i]);
            else um[startTime[i]] = duration[i];
        }
        for(auto c : um) ret.push_back({c.first, c.second});
        sort(ret.begin(), ret.end());
        return ret;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = 1e6;
        vector<pair<int, int>> landTime = sortTime(landStartTime, landDuration);
        vector<pair<int, int>> waterTime = sortTime(waterStartTime, waterDuration);;
        int landSz = landTime.size(), waterSz = waterTime.size();
        vector<int> landEndTime(landSz), waterEndTime(waterSz);
        priority_queue<int, vector<int>, greater<int>> landTot, waterTot;

        int minTime = 1e6;
        for(int i=landSz - 1; i>-1; i--){
            minTime = min(minTime, landTime[i].first + landTime[i].second);
            landEndTime[i] = minTime;
            landTot.push(landTime[i].first + landTime[i].second);
        }
        minTime = 1e6;
        for(int i=waterSz - 1; i>-1; i--){
            minTime = min(minTime, waterTime[i].first + waterTime[i].second);
            waterEndTime[i] = minTime;
            waterTot.push(waterTime[i].first + waterTime[i].second);
        }
        // 육지를 먼저 탑승 // 탑승후 시간으로 정렬
        int idx = 0; // 물놀이기구 탐색용 index
        minTime = 1e6;
        while(landTot.size()){
            int endTime = landTot.top(); landTot.pop();
            while(idx < waterSz && endTime > waterTime[idx].first){
                minTime = min(minTime, waterTime[idx].second); // 개장한 놀이기구중 최단 운행시간
                idx++;
            }
            int totTime = (idx < waterSz ? min(endTime + minTime, waterEndTime[idx]) : endTime + minTime);
            ans = min(ans, totTime);
        }
        // 물을 먼저 시작 // 탑승후 시간으로 정렬
        idx = 0; // 육지놀이기구 탐색용 index
        minTime = 1e6;
        while(waterTot.size()){
            int endTime = waterTot.top(); waterTot.pop();
            while(idx < landSz && endTime > landTime[idx].first){
                minTime = min(minTime, landTime[idx].second); // 개장한 놀이기구중 최단 운행시간
                idx++;
            }
            int totTime = (idx < landSz ? min(endTime + minTime, landEndTime[idx]) : endTime + minTime);
            ans = min(ans, totTime);
        }
        return ans;
    }
};