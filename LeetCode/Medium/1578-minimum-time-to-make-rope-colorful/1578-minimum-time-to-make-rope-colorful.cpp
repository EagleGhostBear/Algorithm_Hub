class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        char prev = '0';
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<colors.size(); i++){
            if(prev == colors[i]) pq.push(neededTime[i]);
            else{
                while(pq.size() > 1){
                    ans += pq.top();
                    pq.pop();
                }
                while(pq.size()) pq.pop();
                pq.push(neededTime[i]);
                prev = colors[i];
            }
        }
        while(pq.size() > 1){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};