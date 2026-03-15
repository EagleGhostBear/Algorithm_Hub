typedef long long ll;

class Solution {
public:
    struct node{
        ll totTime; // 현재까지 작업 총시간(정렬 기준)
        ll workerTime;
        ll cntWork;
        ll equalWorker;
    };
    struct compare{
        // 실제로 봐야하는건 다음 총시간이 가장 낮은것
        bool operator()(node left, node right){
            int nextLeft = left.workerTime * left.cntWork;
            int nextRight = right.workerTime * right.cntWork;
            if(left.totTime + nextLeft > right.totTime + nextRight) return true;
            if(left.totTime + nextLeft < right.totTime + nextRight) return false;
            return false;
        }
    };
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll ans = 0;
        unordered_map<ll, ll> um;
        priority_queue<node, vector<node>, compare> pq;
        for(auto n : workerTimes) um[n]++;
        for(auto n : um) pq.push({0, n.first, 1, n.second});
        while(mountainHeight > 0){ // pq는 항상 있음
            node now = pq.top(); pq.pop();
            now.totTime += now.workerTime * now.cntWork++;
            mountainHeight -= now.equalWorker;
            pq.push(now);
        }
        while(pq.size()){
            node now = pq.top(); pq.pop();
            ans = max(ans, now.totTime);
        }
        return ans;
    }
};
/*
workerTimes[i] 가 같은애들은 한번만 계산
*/