#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> players, int m, int k) {
    int ans = 0;
    
    for(int i=0; i<players.size(); i++){
        int p = players[i];
        while(pq.size() && pq.top() + k <= i) pq.pop();
        while(p >= (pq.size()+1) * m){
            ans++;
            pq.push(i);
        }
    }
    return ans;
}