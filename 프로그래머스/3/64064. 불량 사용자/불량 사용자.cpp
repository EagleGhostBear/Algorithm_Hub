#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int ans = 0;
vector<vector<string>> v;
vector<vector<int>> vi;
unordered_map<int, bool> visited;
unordered_map<string, int> user_idx;

bool match_id(string& ori, string& ban){
    if(ori.size() != ban.size()) return false;
    int i = 0, start_idx = 0;
    for(; i<ban.size(); i++){
        if(ban[i] == '*'){
            if(start_idx != i){
                if(ori.substr(start_idx, i - start_idx) != ban.substr(start_idx, i - start_idx)) return false;
            }
            start_idx = i + 1;
        }
    }
    if((start_idx != i) && (ori.substr(start_idx, i - start_idx) != ban.substr(start_idx, i - start_idx))) return false;
    return true;
}

void solve(int level, int bitmask){
    if(level == -1){
        visited[bitmask] = true;
        return;
    }
    for(int i=0; i<vi[level].size(); i++){
        if(bitmask & (1 << vi[level][i])) continue;
        bitmask |= (1 << vi[level][i]);
        solve(level - 1, bitmask);
        bitmask &= ~(1 << vi[level][i]);
    }
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    for(int i=0; i<user_id.size(); i++) user_idx[user_id[i]] = i;
    v.resize(banned_id.size(), vector<string>());
    vi.resize(banned_id.size(), vector<int>());
    for(int i=0; i<banned_id.size(); i++) for(int j=0; j<user_id.size(); j++){
        if(match_id(user_id[j], banned_id[i])) v[i].push_back(user_id[j]);
    }
    for(int i=0; i<v.size(); i++) for(int j=0; j<v[i].size(); j++){
        vi[i].push_back(user_idx[v[i][j]]);
    }
    solve(banned_id.size() - 1, 0);
    return visited.size();
}
/*
1. 자리수
*/