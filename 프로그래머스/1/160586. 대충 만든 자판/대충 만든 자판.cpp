#include <string>
#include <vector>

using namespace std;

vector<int> v(26, 1e9);

vector<int> solution(vector<string> keymap, vector<string> targets) {
    for(int i=0; i<keymap.size(); i++){
        for(int j=0; j<keymap[i].size(); j++){
            int val = keymap[i][j] - 'A';
            v[val] = min(v[val], j + 1);
        }
    }
    vector<int> answer;
    for(int i=0; i<targets.size(); i++){
        int cnt = 0;
        for(int j=0; j<targets[i].size(); j++){
            int val = targets[i][j] - 'A';
            cnt += v[val];
            if(v[val] == 1e9) break;
        }
        if(cnt >= 1e9) answer.push_back(-1);
        else answer.push_back(cnt);
    }
    return answer;
}