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

ll ans = 1e17;
ll len = 0, totLine = 0;
string s;
vector<int> numLine = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 5 };
vector<vector<ll>> dp; // dp[자리수][총 라인수] = 만들 수 있는 최소값

int getLine(string num){
    int ret = 0;
    for(auto c : num) ret += numLine[c - '0'];
    return ret;
}

string covertString(ll num, int numLen){
    string ret = to_string(num);
    while(ret.size() < numLen) ret = '0' + ret;
    return ret;
}

// 현재 카운터 s 보다 큰 수중에서 같은 선분의 개수를 가지는것을 찾는 함수
bool isBigger(){
    for(int loc=s.size() - 1; loc>-1; loc--){ // 1의 자리부터 값을 증가시켜가며 같은 선분수를 가지는 더 큰수를 찾는다.
        int initLine = getLine(s.substr(0, loc));
        int remLen = s.size() - (loc + 1); // 앞에서부터 loc 까지의 숫자가 확정됐다고 가정했을때, 나머지 확정해야 하는 자리수
            for(int locNum = s[loc] - '0' + 1; locNum < 10; locNum++){
            int frontLine = initLine + numLine[locNum]; // 앞에서부터 loc 자리에 locNum이 왔을때 loc자리까지 총 선분의 수
            /*
            remLine = totLine - frontLine; // 앞부분을 확정했을 때 미확정 뒷부분의 총 선분의 수
            즉, dp[remLen - 1][totLine - remLine] 의 의미는 remLen 길이의 remLine 선분 개수로 만들 수 있는 조합이 있는지 확인한다는 의미이다.
            만약 dp[remLen - 1][totLine - remLine] 이 갱신된 적 없는 1e16 이라면 해당 글자 수로는 해당 선분 개수의 조합을 만들 수 없다는 의미이다.
            */
            if(remLen){
                if(frontLine <= totLine && dp[remLen - 1][frontLine] < 1e16){
                    string ret = s.substr(0, loc) + char(locNum + '0') + covertString(dp[remLen - 1][frontLine], remLen);
                    ans = stoll(ret) - stoll(s);
                    return true;
                }
            }
            else{ // 1의 자리를 탐색할 때
                string ret = s.substr(0, loc) + char(locNum + '0');
                if(totLine == getLine(ret)){
                    ans = stoll(ret) - stoll(s);
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    len = s.size(); // 카운터 수 길이
    totLine = getLine(s); // 총 선분의 수
    dp.assign(len, vector<ll>(totLine + 1, 1e16));

    // 첫번째 자리에 0 - 9 까지의 숫자가 왔을때의 최소값, min 을 쓰는건 선분의 수가 같은 숫자들이 있기 때문에
    for (ll i = 0; i < 10; i++) if(totLine - numLine[i] >= 0) dp[0][totLine - numLine[i]] = min(dp[0][totLine - numLine[i]], i);
    // 마지막 자리까지 0 - 9 를 넣어보면서 가능한 경우의 수에서 최소값을 계산
    for (int idx = 1; idx < s.size(); idx++) { // 15 * 105 * 10 = 15,750
        for (int i = totLine; i > -1; i--) {
            for (int j = 0; j < 10; j++) { // 이번에 추가될 숫자
                if (i + numLine[j] > totLine) continue;
                dp[idx][i] = min(dp[idx][i], dp[idx - 1][i + numLine[j]] * 10 + j);
            }
        }
    }
    if(isBigger()) cout << ans;
    else{ // 이미 dp 초기화 과정에서 특정 조합에서의 최저값을 구했으므로 그대로 사용
        ll maxNum = 1;
        for(int i=0; i<len; i++) maxNum *= 10;
        cout << dp[len - 1][0] + (maxNum - stoll(s));
    }
}