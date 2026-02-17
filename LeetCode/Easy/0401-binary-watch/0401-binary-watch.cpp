class Solution {
public:
    void cal_binary(vector<vector<int>>& time, int idx, int level, int tot){
        for(int i=idx+1; i<time.size(); i++){
            int nextTot = tot + (1 << i);
            if(level + 1 > time.size()) continue;
            if(time.size() == 4 && nextTot > 11) continue;
            if(time.size() == 6 && nextTot > 59) continue;
            time[level].push_back(nextTot);
            cal_binary(time, i, level + 1, nextTot);
        }
        return;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        vector<vector<int>> h(4, vector<int>());
        vector<vector<int>> m(6, vector<int>());
        h[0].push_back(0);
        m[0].push_back(0);
        cal_binary(h, -1, 1, 0);
        cal_binary(m, -1, 1, 0);
        for(int i=0; i<=3; i++) for(int j=0; j<=5; j++){
            if(i + j != turnedOn) continue;
            for(int a=0; a<h[i].size(); a++){
                for(int b=0; b<m[j].size(); b++){
                    string hour = to_string(h[i][a]);
                    string min = (m[j][b] < 10 ? '0' + to_string(m[j][b]) : to_string(m[j][b]));
                    ans.push_back(hour + ':' + min);
                }
            }
        }
        return ans;
    }
};