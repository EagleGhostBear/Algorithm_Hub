typedef long long ll;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>> alp(26, vector<ll>(26, 1e9));
        for(int i=0; i<26; i++) alp[i][i] = 0;
        for(int i=0; i<original.size(); i++){
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            alp[from][to] = min(alp[from][to], (ll)cost[i]);
        }
        for(int from=0; from<26; from++) for(int to=0; to<26; to++){
            for(int mid=0; mid<26; mid++) if(alp[from][mid] < 1e9 && alp[mid][to] < 1e9){
                alp[from][to] = min(alp[from][to], alp[from][mid] + alp[mid][to]);
            }
        }
        ll ans = 0;
        for(int i=0; i<source.size(); i++){
            ll now = alp[source[i] - 'a'][target[i] - 'a'];
            if(now >= 1e9) return -1;
            else ans += now;
        }
        return ans;
    }
};
/*
만약 더 작게 갱신됐으면 앞, 뒤로 연관된 애들을 전부 갱신해줘야함
ex) c -> e (1), e -> b (2) => c -> b (3) 으로 되는것이다.
*/