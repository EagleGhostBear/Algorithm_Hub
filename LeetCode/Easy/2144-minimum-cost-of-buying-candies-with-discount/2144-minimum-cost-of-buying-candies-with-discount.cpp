class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans = 0;
        priority_queue<int> pq;
        for(auto n : cost) pq.push(n);
        while(pq.size()){
            if(pq.size() >= 3){
                for(int i=0; i<2; i++) {ans += pq.top(); pq.pop();}
                pq.pop();
            }
            else{
                while(pq.size()) {ans += pq.top(); pq.pop();}
            }
        }
        return ans;
    }
};