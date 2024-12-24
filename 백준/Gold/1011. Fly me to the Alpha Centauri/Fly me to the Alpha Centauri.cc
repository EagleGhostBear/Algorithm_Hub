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
        ll from, to, target, speed = 1, cnt = 0;
        cin >> from >> to;
        target = to - from;

        if (target < 2) {
            target -= 1;
            cnt += 1;
            //cout << "first 1 STEP: " << speed << endl;
        }
        else {
            target -= 2;
            cnt += 2;
            //cout << "first 2 STEP: " << 2*speed << endl;
        }

        while (target) {
            if (target >= 2*(speed + 1)) {
                speed += 1;
                target -= (2 * speed);
                cnt += 2;
                //cout << "2 STEP: " << 2*speed << endl;
            }
            else if (target >= speed + 1) {
                speed += 1;
                target -= speed;
                cnt += 1;
                //cout << "1 STEP: " << speed << endl;
            }
            else if (target >= speed) {
                target -= speed;
                cnt += 1;
                //cout << "1 STEP: " << speed << endl;
            }
            else {
                target = 0;
                cnt += 1;
                //cout << "last STEP: " << speed << endl;
            }
        }

        cout << cnt << "\n";
    }
}
/*
x, y <= int 마지노선
다음 속도 => -1, 0, 1

결국 올라간 속도는 다시 내려와야 한다
목표 거리 = (y - x)
k(짝수) = 1(2) 
*/