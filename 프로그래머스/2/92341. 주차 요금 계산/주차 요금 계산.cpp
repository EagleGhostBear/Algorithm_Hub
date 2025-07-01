#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<int, int> um;
unordered_map<int, int> use_time;
vector<pair<int, int>> ans;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for(int i=0; i<records.size(); i++){
        int num = stoi(records[i].substr(6, 4));
        int time = stoi(records[i].substr(0, 2)) * 60 + stoi(records[i].substr(3, 2));
        string state = records[i].substr(11, 2);
        if(state == "IN") um[num] = time;
        else if(state == "OU"){
            use_time[num] += (time - um[num]);
            um[num] = -1;
        }
    }
    for(auto data : um) if(data.second >= 0) use_time[data.first] += (1439 - data.second);
    for(auto data : use_time){
        int price = fees[1];
        if(data.second > fees[0]){
            price += (data.second - fees[0])/fees[2]*fees[3];
            if((data.second - fees[0])%fees[2]) price += fees[3];
        }
        ans.push_back({data.first, price});
    }
    sort(ans.begin(), ans.end());
    for(auto data : ans) answer.push_back(data.second);
    return answer;
}