#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int t;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--){
        ll from, to, target, speed = 0, cnt = 0;
        cin >> from >> to;
        target = to - from;

        while (target) {
            if (target >= 2*(speed + 1)) { // 스피드가 증가 될때 내려오는 것까지 생각해서 *2
                speed += 1;
                target -= (2 * speed);
                cnt += 1;
            }
            else if (target >= speed + 1) { // speed 증가가 1번만
                speed += 1;
                target -= speed;
            }
            else { // 현재 나왔던 속도들 중 1개의 속도를 그대로 유지하면 target 값에 도달한다는 의미
                target = 0;
            }
            cnt += 1;
        }

        cout << cnt << "\n";
    }
}
/*
x, y <= int 마지노선, long long 사용
다음 속도 => -1, 0, 1

결국 올라간 속도는 다시 내려와야 한다 -> 속도 증가를 *2 로 생각하여 내려오는것 까지 생각
목표 거리 = (y - x)
*/