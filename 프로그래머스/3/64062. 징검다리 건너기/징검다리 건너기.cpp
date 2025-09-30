#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

int ans = 1e9;
deque<int> dq;
unordered_map<int, int> um; // um[값] = 개수
priority_queue<int> pq;

void rm_num(){ // 현재 최고값이 실제로 있는지 검증 후 없다면 삭제
    while(pq.size() && um[pq.top()] == 0) pq.pop();
    return;
}

int solution(vector<int> stones, int k) {
    for(int i=0; i<k; i++){
        dq.push_back(stones[i]);
        pq.push(stones[i]);
        um[stones[i]]++;
    }
    ans = min(ans, pq.top());
    for(int i=k; i<stones.size(); i++){
        // 앞부분 제거
        um[dq.front()]--;
        dq.pop_front();
        // pq.pop(); // 앞부분 값이 pq.top 값으로 볼 수 없음
        rm_num();
        
        // 뒷부분 추가
        um[stones[i]]++;
        dq.push_back(stones[i]);
        pq.push(stones[i]);
        
        ans = min(ans, pq.top());
    }
    return ans;
}
/*
최악 : 내림차순이라 계속 최대값을 새로 찾아야 하는 경우
*/