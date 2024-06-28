#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int total = 0;
int now = 1; // -1, 1

int main(int argc, char** argv)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    int val = 0;
    bool chk = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') {
            if (chk) { // -로 처리되는 + 값들
                total -= val;
            }
            else { // +로 처리 되는 값들
                total += val;
            }
            val = 0;
        }
        else if (s[i] == '-') {
            if (chk) { // 두번째 -
                total -= val;
            }
            else { // 첫번째 -
                chk = true;
                total += val;
            }
            val = 0;
        }
        else { // 숫자
            val *= 10;
            val += int(s[i]) - int('0');
        }
    }
    if (chk) {
        total -= val;
    }
    else {
        total += val;
    }

    cout << total;
}