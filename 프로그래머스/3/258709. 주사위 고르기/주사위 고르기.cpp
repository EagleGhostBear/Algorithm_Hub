#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

struct node{
    int level, bitmask;
};

pair<int, int> ans = {0, 0};
vector<map<int, int>> dp; // dp[bitmask] = {{값, 개수}, ...}
map<int, bool> m;

void sel_dice(vector<vector<int>>& dice){
    queue<node> q;
    int sz = dice.size() / 2;
    for(int i=0; i<dice.size(); i++){
        q.push({sz - 1, (1 << i)});
    }
    
    while(q.size()){
        node now = q.front();
        q.pop();
        if(now.level == 0){
            int rbitmask = ((1 << dice.size()) - 1) & ~now.bitmask;
            if(m[now.bitmask] || m[rbitmask]) continue;
            m[now.bitmask] = true;
            m[rbitmask] = true;
            
            pair<int, int> result = {0, 0};
            for(auto a : dp[now.bitmask]) for(auto b : dp[rbitmask]){
                int val = a.second * b.second;
                if(a.first > b.first) result.first += val;
                else if(a.first < b.first) result.second += val;
            }
            if(ans.first < result.first) {ans.first = result.first; ans.second = now.bitmask;}
            if(ans.first < result.second) {ans.first = result.second; ans.second = rbitmask;}
            continue;
        }
        
        for(int i=0; i<dice.size(); i++){
            if(now.bitmask & (1 << i)) continue;
            if(dp[now.bitmask | (1 << i)].size()) continue;
            for(auto a : dp[now.bitmask]) for(auto b : dp[(1 << i)]){
                dp[now.bitmask | (1 << i)][a.first + b.first] += (a.second * b.second);
            }
            q.push({now.level - 1, now.bitmask | (1 << i)});
        }
    }
    return;
}

vector<int> solution(vector<vector<int>> dice) {
    dp.resize((1 << dice.size()) - 1, map<int, int>());
    for(int i=0; i<dice.size(); i++) for(int j=0; j<dice[i].size(); j++) {
        dp[(1 << i)][dice[i][j]] += 1;
    }
    sel_dice(dice);
    
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