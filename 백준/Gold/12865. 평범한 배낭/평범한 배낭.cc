#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>

using namespace std;

struct node {
    int w;
    int v;
};

int n, k;
int maxv = 0;
int dp[101][100001];
vector<node> jew;

void find_dp() {
    for (int limit = 0; limit <= k; limit++) { // 무게한도
        for (int row = 0; row <= n; row++) {
            // 1. 무게 제한이 0 이거나 현재 사용 보석수가 0 일때
            if (limit == 0 || row == 0) {
                dp[row][limit] = 0;
            }
            // 2. 담을 수 없을 경우
            else if (jew[row].w > limit) {
                dp[row][limit] = dp[row - 1][limit]; // 이번 보석은 못 담기 때문에 이전 보석 상태를 그대로 가져옴
            }
            // 3. 담을 수 있는 경우
            else {
                dp[row][limit] = max(dp[row - 1][limit - jew[row].w] + jew[row].v, dp[row - 1][limit]);
            }
            maxv = max(maxv, dp[row][limit]);
        }
    }

}

int main(int argc, char** argv)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k; // 물품수 // 무게한도
    jew.push_back({ 0, 0 });
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        jew.push_back({ w, v });
    }

    find_dp();

    cout << maxv;
}