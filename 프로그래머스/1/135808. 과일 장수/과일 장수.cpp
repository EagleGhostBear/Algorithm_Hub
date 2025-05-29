#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end(), greater<int>());
    int cnt = 0, val = 10;
    for(int i=0; i<score.size(); i++){
        if(cnt < m){
            val = min(val, score[i]);
            cnt++;
            if(cnt == m){
                answer += val*m;
                cnt = 0;
                val = 10;
            }
        }
    }
    return answer;
}