#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int due_start = 60; // 59+1
int due_end = 334; // 304+30

struct node {
    int start;
    int end;

    bool operator<(node right) const {
        if (start < right.start) { return false; }
        if (start > right.start) { return true; }

        if (end < right.end) { return true; }
        if (end > right.end) { return false; }

        return false;
    }
};

int n;
int cnt = 0;
int month[] = { -1, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
priority_queue<node> pq;

int main(int argc, char** argv)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int start = month[a] + b;
        int end = month[c] + d - 1;

        // 3월 1일 ~ 11월 30일 범위에서 벗어난 것들 제거
        if (end < due_start) {
            continue;
        }
        else if (due_end < start) {
            continue;
        }

        if (start <= due_start) {
            start = due_start;
        }
        if (due_end <= end) {
            end = due_end;
        }
        pq.push({ start, end });
    }

    while (!pq.empty()) {
        priority_queue<node> tmp;
        node first = pq.top();
        pq.pop();
        cnt += 1;
        if (due_start < first.start) { // 날짜가 이어지는 꽃이 없음
            cout << "0";
            exit(0);
        }
        else { // 이어지는 꽃이 있으면 기준 갱신
            due_start = first.end + 1;
        }
        if (first.end == due_end) {
            cout << cnt;
            exit(0);
        }

        while (!pq.empty()) {
            node now = pq.top();
            pq.pop();
            if (now.end < due_start) {
                continue;
            }
            if (due_start < now.start) {
                tmp.push({ now.start, now.end });
            }
            else {
                tmp.push({ due_start, now.end });
            }
        }
        pq = tmp;
    }

    cout << "0";
}