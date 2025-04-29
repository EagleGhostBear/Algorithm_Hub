#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<vector<int>> v; // v[from][to] = 선물 개수
vector<pair<int, int>> total; // total[사람] = {준선물, 받은선물}
unordered_map<string, int> um; // 해당 이름의 idx 파악

int solution(vector<string> friends, vector<string> gifts) {
    v.resize(friends.size(), vector<int>(friends.size(), 0));
    total.resize(friends.size(), pair<int, int>());
    for(int i=0; i<friends.size(); i++) um[friends[i]] = i;
    for(int i=0; i<gifts.size(); i++){
        int idx = 0;
        for(;idx<gifts[i].size(); idx++) if(gifts[i][idx] == ' ') break;
        int from = um[gifts[i].substr(0, idx)];
        int to = um[gifts[i].substr(idx + 1)];
        v[from][to]++;
        total[from].first++;
        total[to].second++;
    }
    
    int ans = 0;
    for(int i=0; i<friends.size(); i++){
        int cnt = 0;
        for(int j=0; j<friends.size(); j++){
            if(j == i) continue;
            if(v[i][j] > v[j][i]) cnt++;
            else if(v[i][j] == v[j][i]){
                int score_a = total[i].first - total[i].second;
                int score_b = total[j].first - total[j].second;
                if(score_a > score_b) cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    
    return ans;
}