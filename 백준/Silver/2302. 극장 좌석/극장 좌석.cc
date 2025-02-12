#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n, m;
vector<vector<int>> dp; // dp[좌석번호][좌석 기준 -1, 0] = 경우의 수
vector<int> vip;
// dp[][0] -> -1
// dp[][1] -> 0
// dp[][2] -> 1

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    dp.resize(n + 1, vector<int>(2, 0));
    vip.resize(n + 1, 0);
    dp[0][1] = 1; // 아무것도 배치하지 않았을때 1개의 경우
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        vip[tmp] = 1;
    }

    for (int num = 1; num <= n; num++) {
        // num-1, num 좌석 교환
        if (num >= 2 && !vip[num - 1] && !vip[num]) { // num-1, num 좌석 VIP라면 고정되기 교환이 안됨
            // num-1, num이 고정이 되기 때문에 num-2에서 가져옴
            dp[num][0] += (dp[num - 2][0] + dp[num-2][1]);
        }
        // 좌석 교환없이 그대로 num에 앉는 경우
        dp[num][1] += (dp[num - 1][0] + dp[num - 1][1]); // num 좌석 고정되기 때문에 num-1에서 가져옴
    }
    cout << dp[n][0] + dp[n][1];
}
/*
좌석번호 -1, 0, 1 까지 앉기 가능
VIP = 반드시 자기 좌석(옮기기 불가)
주의) 상태가 3개라 -1, 0, 1 이라고 선언하면 안됨
뒤의 존재를 모르는 상태에서 뒤에서 빌려오는 상태인 1은 말이 안됨 -1, 0 의 경우만 생각
*/