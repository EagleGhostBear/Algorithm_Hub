typedef long long ll;

class Solution {
public:
    struct node{ ll tot, weight; };
    void addData(queue<node>& q, vector<ll>& w, node& now){
        if(w[now.weight] < now.tot){
            w[now.weight] = now.tot;
            q.push(now);
        }
        return;
    }
    long long maxSumTrionic(vector<int>& nums) {
        ll ans = -1e15;
        queue<node> q;
        for(int i=0; i<nums.size(); i++){
            int diff = (i ? nums[i] - nums[i - 1] : 0);
            vector<ll> w(4, -1e15);
            int sz = q.size();
            for(int j=0; j<sz; j++){
                node now = q.front(); q.pop();
                now.tot += nums[i];

                // diff = 0 생략
                if(diff > 0){
                    // weight = 0, 1, 2, 3
                    if(now.weight % 2){
                        if(now.weight == 3) ans = max(ans, now.tot);
                        addData(q, w, now);
                    }
                    else{
                        if(now.weight == 2) ans = max(ans, now.tot);
                        now.weight += 1;
                        addData(q, w, now);
                    }
                }
                else if(diff < 0){
                    if(now.weight == 1) {now.weight += 1; addData(q, w, now);}
                    else if(now.weight == 2) addData(q, w, now);
                }
            }
            sz = q.size();
            for(int j=0; j<sz; j++){
                node now = q.front(); q.pop();
                if(w[now.weight] == now.tot) q.push(now);
            }
            q.push({nums[i], 0});
        }
        return ans;
    }
};
/*
증, 감, 증, 감, 증 -> 이렇듯 3번째 증은 양측에 사용될 수 있다.
따로 배열을 만들어서 값들을 넣고 조건에 안맞는건 빼고 맞는건 계속 갱신해 나간다?
*/