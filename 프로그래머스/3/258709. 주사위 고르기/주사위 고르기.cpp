#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

struct node{
    int level, idx, bitmask;
};

pair<int, int> ans = {0, 0};
vector<map<int, int>> dp; // dp[bitmask] = {{값, 개수}, ...}
vector<vector<pair<int, int>>> v; // v[bitmask] = {{값, 총합개수}}
map<int, bool> m;

void sel_dice(vector<vector<int>>& dice){
    queue<node> q;
    int sz = dice.size() / 2;
    for(int i=0; i<dice.size(); i++){
        q.push({sz - 1, i, (1 << i)});
    }
    
    while(q.size()){
        node now = q.front();
        q.pop();
        if(now.level == 0){
            int rbitmask = ((1 << dice.size()) - 1) & ~now.bitmask;
            if(m[now.bitmask] || m[rbitmask]) continue;
            m[now.bitmask] = true;
            m[rbitmask] = true;
            // 만약 정순이라면 큰수부터
            /*
            정순 : l 큰수부터 반복 -> r 큰수부터 탐색해서 어디부터 지는지 파악 -> 해당 조합 전부 패배
            */
            int i = 0;
            for(auto c : dp[now.bitmask]){
                v[now.bitmask].push_back({c.first, c.second});
                // if(i) v[now.bitmask][i].second += v[now.bitmask][i - 1].second;
                // i++;
            }
            i = 0;
            for(auto c : dp[rbitmask]){
                v[rbitmask].push_back({c.first, c.second});
                // if(i) v[rbitmask][i].second += v[rbitmask][i - 1].second;
                // i++;
            }
            // for(auto c : v[now.bitmask]) cout << c.first << ":" << c.second << " ";
            // cout << "\n";
            // for(auto c : v[rbitmask]) cout << c.first << ":" << c.second << " ";
            // cout << "\n";
            
            pair<int, int> result = {0, 0};
            for(i = 0; i<v[now.bitmask].size(); i++){
                for(int j=0; j<v[rbitmask].size(); j++){
                    int val = v[now.bitmask][i].second * v[rbitmask][j].second;
                    if(v[now.bitmask][i].first > v[rbitmask][j].first) result.first += val;
                    else if(v[now.bitmask][i].first < v[rbitmask][j].first) result.second += val;
                }
            }
            if(ans.first < result.first) {ans.first = result.first; ans.second = now.bitmask;}
            if(ans.first < result.second) {ans.first = result.second; ans.second = rbitmask;}
            // for(i = 0; i<v[now.bitmask].size(); i++){
            //     int l=0, r=v[rbitmask].size() - 1;
            //     int mid;
            //     while(l <= r){
            //         mid = (l + r) / 2;
            //         if(v[now.bitmask][i].first < v[rbitmask][mid].first){
            //             r = mid - 1;
            //         }
            //         else l = mid + 1;
            //     }
            //     cout << v[now.bitmask][i].first << " " << v[rbitmask][mid].first << "\n";
            // }
            continue;
        }
        
        for(int i=now.idx + 1; i<dice.size(); i++){
            if(now.bitmask & (1 << i)) continue;
            for(auto a : dp[now.bitmask]) for(auto b : dp[(1 << i)]){
                dp[now.bitmask | (1 << i)][a.first + b.first] += (a.second * b.second);
            }
            q.push({now.level - 1, i, now.bitmask | (1 << i)});
        }
    }
    return;
}

vector<int> solution(vector<vector<int>> dice) {
    dp.resize((1 << dice.size()) - 1, map<int, int>());
    v.resize((1 << dice.size()) - 1, vector<pair<int, int>>());
    for(int i=0; i<dice.size(); i++) for(int j=0; j<dice[i].size(); j++) {
        dp[(1 << i)][dice[i][j]] += 1;
    }
    sel_dice(dice);
    // cout << ans.first << " " << ans.second;
    vector<int> answer;
    for(int i=0; i<dice.size(); i++){
        if(ans.second & (1 << i)) answer.push_back(i + 1);
    }
    return answer;
}
/*
총합이 높다고 확률이 높은건 아님 ex) 1,1,1,1,1,100 vs 3,3,3,3,3,3 평균의 함정 존재
최대 5 : 5

36 vs 36 -> 1296 * 4C2가지
7776 vs 7776 -> 60,466,176 * 5C2가지 경우의 수

대칭성 #1, #2 <-> #3, 4 는 결국 같은 계산식으로 가기 때문에 2번 계산할 필요없음 승패가 반대일뿐

1. 주사위 n/2 개 조합으로 선택 : 14,400
2. 해당 주사위를 통해 만들어질 수 있는 조합 구하기 : 7,776 * 14,400 -> 이러면 양플레어 모든 조합찾아내기 가능
3. 반대편 주사위 조합과 비교하여 승률 계산
*/