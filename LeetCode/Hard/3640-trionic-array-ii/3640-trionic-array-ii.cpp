typedef long long ll;

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        ll ans = -1e15;
        vector<ll> weight(4, -1e15);
        for(int i=0; i<nums.size(); i++){
            int diff = (i ? nums[i] - nums[i - 1] : 0);
            // cout << "now: " << nums[i] << " diff: " << diff << "\n";
            // for(auto c : weight) cout << c << " "; cout << "\n";
            if(diff == 0){
                ans = max(ans, weight[3]);
                weight.assign(4, -1e15);
            }
            else if(diff > 0){
                // 3
                weight[3] += nums[i];
                // 2
                weight[3] = max(weight[3], weight[2] + nums[i]);
                weight[2] = -1e15;
                // 1
                weight[1] += nums[i];
                // 0
                weight[1] = max(weight[1], weight[0] + nums[i]);
                // weight[0] = -1e15;
            }
            else{
                // 3
                ans = max(ans, weight[3]); weight[3] = -1e15;
                // 2
                weight[2] += nums[i];
                // 1
                weight[2] = max(weight[2], weight[1] + nums[i]);
                weight[1] = -1e15;
            }
            weight[0] = nums[i];
            ans = max(ans, weight[3]);
        }
        return ans;
    }
};
/*
증, 감, 증, 감, 증 -> 이렇듯 3번째 증은 양측에 사용될 수 있다.
따로 배열을 만들어서 값들을 넣고 조건에 안맞는건 빼고 맞는건 계속 갱신해 나간다?
*/