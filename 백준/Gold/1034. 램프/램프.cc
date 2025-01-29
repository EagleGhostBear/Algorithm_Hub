#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n, m, k;
vector<string> v;
unordered_map<string, int> pattern;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pattern[v[i]]++;
    }
    cin >> k;

    int max_row = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (auto c : v[i]) { // 해당 패턴에서 최소 몇번의 k가 필요한지 계산
            if (c == '0') {
                cnt++;
            }
        }
        if (cnt <= k && !((k - cnt) % 2)) { // 필요한 클릭 회수가 k보다 작거나 같은지 확인 // 여분의 k에 대해서 동일 동작을 하는걸로 없앨수 있는지 확인
            max_row = max(max_row, pattern[v[i]]);
        }
    }

    cout << max_row;
}
/*
"열"만 조종 가능
켜져 있는 "행"을 최대로
1. 스위치는 순서에 상관없이 누르는 회수가 결과에 영향을 미친다.
2. 같은 스위치를 2번 누르면 안누른것과 동일하다. 즉, 모든 스위치는 1번만 누를때 의미가 있다.
3. m < k 의 경우 스위치를 중복해서 누르는 경우가 생기므로 굳이 시행을 안해도 상관없다.
4. 초과분인 (k-m) 짝수일 경우: 1개의 스위치를 중복해서 누른다고 가정하고 신경 안써도 된다.
                  홀수일 경우: 1개의 버튼을 2번 눌러야 하므로 오히려 m - 1 을 시행한다고 생각하면 된다.
조합으로 풀 경우 n, m = 50, k = 25가 최대(1e14)로 불가능
5. 같은 패턴을 가진 행끼리는 똑같은 회수로 통일 시킬수 있다.
6. 패턴마다 주어진 k번의 회수로 만들수 있는지 확인 -> 만들수 있는 패턴들중에서 최대값 갱신
*/