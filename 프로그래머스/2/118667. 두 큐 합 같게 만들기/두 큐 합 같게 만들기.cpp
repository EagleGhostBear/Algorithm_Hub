#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

ll total1 = 0, total2 = 0;
queue<int> q1, q2;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    for(int i=0; i<queue1.size(); i++){
        q1.push(queue1[i]);
        total1 += queue1[i];
        q2.push(queue2[i]);
        total2 += queue2[i];
    }
    int sz = queue1.size() * 3;
    bool chk = true;
    for(int i=0; i<sz; i++){
        if(total1 == total2){
            chk = false;
            break;
        }
        else if(total1 > total2){
            total1 -= q1.front();
            total2 += q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else if(total1 < total2){
            total2 -= q2.front();
            total1 += q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        answer++;
    }
    if(chk) return -1;
    else return answer;
}