#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct node {
    int name;
    queue<int> q;

    bool operator<(node right) const {
        if (q.front() < right.q.front()) { return true; }
        if (q.front() > right.q.front()) { return false; }

        if (name < right.name) { return false; }
        if (name > right.name) { return true; }

        return false;
    }
};

int n, k;
int total = 0;
vector<int> v; // 순서
vector<node> dat;
vector<node> sk;

int main(int argc, char** argv) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0; i < 101; i++) {
        node tmp;
        dat.push_back(tmp);
    }
    for (int i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        dat[tmp].name = tmp;
        dat[tmp].q.push(i);
        v.push_back(tmp);
    }
    for (int i = 0; i < 101; i++) {
        dat[i].q.push(1000);
    }

    if (k <= n) {
        cout << "0";
        exit(0);
    }

    for (int i = 0; i < k; i++) {
        int now_name = v[i];
        dat[now_name].q.pop();
        bool chk = false;

        for (int j = 0; j < sk.size(); j++) {
            if (sk[j].name == now_name) { // 이미 콘센트에 꼽혀 있는 경우
                chk = true;
                sk[j].q.pop();
                sort(sk.begin(), sk.end());
                break;
            }
        }
        if (chk) { continue; }

        if (sk.size() < n) { // 콘센트가 비어 있을 경우 -> 뽑는것 없이 바로 꼽는다
            sk.push_back(dat[now_name]);
            sort(sk.begin(), sk.end());
        }
        else { // 콘센트에 자리가 없는 경우 -> 하나 뽑고나서 꼽는다
            sk.pop_back();
            sk.push_back(dat[now_name]);
            total += 1;
            sort(sk.begin(), sk.end());
        }
    }

    cout << total;
}