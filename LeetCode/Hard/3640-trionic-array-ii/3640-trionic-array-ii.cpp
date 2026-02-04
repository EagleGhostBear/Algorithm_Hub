class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long ans = -1e15;
        long long w1, w2, w3;
        w1 = w2 = w3 = -1e15;
        for(int i=1; i<nums.size(); i++){
            int diff = (i ? nums[i] - nums[i - 1] : 0);
            if(diff == 0) w1 = w2 = w3 = -1e15;
            else if(diff > 0){
                // 3
                w3 += nums[i];
                // 2
                w3 = max(w3, w2 + nums[i]);
                w2 = -1e15;
                // 1
                w1 += nums[i];
                // 0
                w1 = max(w1, (long long)nums[i - 1] + nums[i]);
            }
            else{
                // 3
                w3 = -1e15;
                // 2
                w2 += nums[i];
                // 1
                w2 = max(w2, w1 + nums[i]);
                w1 = -1e15;
            }
            ans = max(ans, w3);
        }
        return ans;
    }
};
/*
증, 증감, 증감증 -> 각 상태는 중복해서 존재할 필요가 없다. 해당 상태를 단일로 관리한다.
*/