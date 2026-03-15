typedef long long ll;

class Solution {
public:
    struct node{
        ll totTime; // 이 작업을 선반영한 총시간
        ll workerTime;
        ll cntWork;
        ll equalWorker;
    };
    struct compare{
        bool operator()(node left, node right){
            if(left.totTime > right.totTime) return true;
            if(left.totTime < right.totTime) return false;
            return false;
        }
    };
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll ans = 0;
        unordered_map<ll, ll> um;
        priority_queue<node, vector<node>, compare> pq;
        for(auto n : workerTimes) um[n]++;
        for(auto n : um) pq.push({n.first, n.first, 2, n.second});
        while(mountainHeight > 0){ // pq는 항상 있음
            node now = pq.top(); pq.pop();
            now.totTime += now.workerTime * now.cntWork++;
            mountainHeight -= now.equalWorker;
            pq.push(now);
        }
        while(pq.size()){
            node now = pq.top(); pq.pop();
            // 선반영된 시간을 빼야함
            ans = max(ans, now.totTime - (now.workerTime * --now.cntWork));
        }
        return ans;
    }
};
/*
workerTimes[i] 가 같은애들은 한번만 계산
*/