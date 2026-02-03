typedef long long ll;

class Solution {
public:
    void solve(vector<vector<ll>>& alp, int from, int to, int cost){
        if(alp[from][to] <= cost) return;
        alp[from][to] = cost;
        for(int i=0; i<26; i++){
            solve(alp, i, to, alp[i][from] + cost);
            solve(alp, from, i, cost + alp[to][i]);
        }
        return;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>> alp(26, vector<ll>(26, 1e9));
        for(int i=0; i<original.size(); i++){
            solve(alp, original[i] - 'a', changed[i] - 'a', cost[i]);
        }
        ll ans = 0;
        for(int i=0; i<source.size(); i++){
            if(source[i] != target[i]){
                ll now = alp[source[i] - 'a'][target[i] - 'a'];
                if(now >= 1e9) return -1;
                else ans += now;
            }
        }
        return ans;
    }
};
/*
만약 더 작게 갱신됐으면 앞, 뒤로 연관된 애들을 전부 갱신해줘야함
ex) c -> e (1), e -> b (2) => c -> b (3) 으로 되는것이다.
*/