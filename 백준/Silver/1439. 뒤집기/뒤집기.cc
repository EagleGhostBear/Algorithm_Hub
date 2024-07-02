#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>

using namespace std;

int n;
int cnt1 = 0;
int cnt2 = 0;
vector<int> v;

int main(int argc, char** argv)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string tmp;
    cin >> tmp;
    char now;
    for (int i = 1; i < tmp.size(); i++) {
        now = tmp[i];
        if (tmp[i] != tmp[i - 1]) {
            if (tmp[i - 1] == '0') {
                cnt1 += 1;
            }
            else {
                cnt2 += 1;
            }
        }
    }

    if (tmp[tmp.size() - 1] != tmp[tmp.size() - 2]) {
        if (tmp[tmp.size() - 2] == '0') {
            cnt2 += 1;
        }
        else {
            cnt1 += 1;
        }
    }
    else {
        if (tmp[tmp.size() - 1] == '0') {
            cnt1 += 1;
        }
        else {
            cnt2 += 1;
        }
    }

    cout << min(cnt1, cnt2);
}