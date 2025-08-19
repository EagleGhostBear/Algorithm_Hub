#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n, m, k;
vector<int> lier, chk;
vector<vector<int>> party, people;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    lier.resize(n + 1);
    chk.resize(m);
    party.resize(m, vector<int>());
    people.resize(n + 1, vector<int>());
    for (int i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        lier[tmp] = 1;
        q.push(tmp);
    }
    for (int i = 0; i < m; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            int tmp;
            cin >> tmp;
            party[i].push_back(tmp);
            people[tmp].push_back(i);
        }
    }
    int cnt = 0;
    while (q.size()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < people[now].size(); i++) {
            int now_party = people[now][i];
            if (chk[now_party]) continue;
            chk[now_party] = 1;
            cnt++;
            for (int j = 0; j < party[now_party].size(); j++) {
                int now_people = party[now_party][j];
                if (lier[now_people]) continue;
                lier[now_people] = 1;
                q.push(now_people);
            }
        }
    }
    cout << m - cnt;
}
/*

*/