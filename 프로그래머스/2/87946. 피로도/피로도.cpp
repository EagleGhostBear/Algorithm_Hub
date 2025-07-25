#include <string>
#include <vector>

using namespace std;

int ans = 0;

void solve(int level, int visited, int hp, vector<vector<int>> v){
    ans = max(ans, level);
    
    for(int i=0; i<v.size(); i++){
        if(visited & (1<<i)) continue;
        if(v[i][0] > hp) continue;
        solve(level + 1, visited | (1 << i), hp - v[i][1],v);
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    solve(0, 0, k, dungeons);
    return ans;
}