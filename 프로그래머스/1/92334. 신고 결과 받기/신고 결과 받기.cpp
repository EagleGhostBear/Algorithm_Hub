#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> cnt;
unordered_map<string, unordered_map<string, bool>> um;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    for(int i=0; i<report.size(); i++){
        int idx = report[i].find(' ');
        string from = report[i].substr(0, idx);
        string to = report[i].substr(idx + 1);
        um[to][from] = true;
    }
    for(auto data : um){
        if(data.second.size() >= k){
            for(auto name : data.second) cnt[name.first]++;
        }
    }
    for(int i=0; i<id_list.size(); i++){
        answer[i] = cnt[id_list[i]];
    }
    return answer;
}