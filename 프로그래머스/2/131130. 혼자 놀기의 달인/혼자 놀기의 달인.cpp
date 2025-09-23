#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

void open_box(int idx, vector<int>& cards){
    int cnt = 0;
    queue<int> q;
    q.push(idx);
    while(q.size()){
        int now = q.front();
        q.pop();
        cnt++;
        
        if(cards[now]){
            q.push(cards[now] - 1);
            cards[now] = 0;
        }
        else cnt--;
    }
    pq.push(cnt);
    return;
}

int solution(vector<int> cards) {
    for(int i=0; i<cards.size(); i++){
        if(cards[i]) open_box(i, cards);
    }
    
    if(pq.size() == 1) return 0;
    int answer = pq.top();
    pq.pop();
    answer *= pq.top();
    return answer;
}