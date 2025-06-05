#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<int> pq;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    for(int i=0; i<enemy.size(); i++){
        n -= enemy[i];
        pq.push(enemy[i]);
        while(n < 0 && k){
            n += pq.top();
            pq.pop();
            k--;
        }
        if(n < 0) break;
        answer++;
    }
    return answer;
}