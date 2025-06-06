#include <string>
#include <vector>

using namespace std;

int answer = 0;

void solve(int idx, int total, int level, vector<int> number){
    if(level == 3){
        if(total == 0) answer++;
        return;
    }
    
    for(int i=idx + 1; i<number.size(); i++){
        solve(i, total + number[i], level + 1, number);
    }
    return;
}

int solution(vector<int> number) {
    solve(-1, 0, 0, number);
    return answer;
}