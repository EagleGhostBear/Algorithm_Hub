typedef long long ll;

class Solution {
public:
    struct node{
        ll row, col, val;
    };
    int maxProductPath(vector<vector<int>>& grid) {
        ll mod = 1e9 + 7;
        vector<vector<pair<ll, ll>>> v(grid.size(), vector<pair<ll, ll>>(grid[0].size(), {-1, 1}));
        int dr[] = {0, 1};
        int dc[] = {1, 0};
        queue<node> q;
        q.push({0, 0, 1});
        while(q.size()){
            node now = q.front(); q.pop();
            ll val = now.val * grid[now.row][now.col];
            if(val >= 0){
                if(val <= v[now.row][now.col].first) continue;
                v[now.row][now.col].first = val;
            }
            else{
                if(val >= v[now.row][now.col].second) continue;
                v[now.row][now.col].second = val;
            }
            for(int i=0; i<2; i++){
                int nr = now.row + dr[i];
                int nc = now.col + dc[i];
                if(nr < 0 || nc < 0 || nr >= v.size() || nc >= v[0].size()) continue;
                q.push({nr, nc, val});
            }
        }
        v.back().back().first %= mod;
        if(v.back().back().first >= 0) return v.back().back().first;
        return -1;
    }
};
/*
각좌표에서 음수라면 가장 작고, 양수라면 가장 큰값을 저장해야함

*/