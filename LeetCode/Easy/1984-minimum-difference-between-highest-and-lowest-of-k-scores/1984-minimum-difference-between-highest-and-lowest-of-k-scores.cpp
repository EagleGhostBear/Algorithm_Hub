class Solution {
public:
    int solve(deque<int>& dq){
        return dq.back() - dq.front();
    }
    int minimumDifference(vector<int>& nums, int k) {
        int ans = 1e9;
        sort(nums.begin(), nums.end());
        deque<int> dq;
        for(int i=0; i<k; i++) dq.push_back(nums[i]);
        ans = min(ans, solve(dq));
        for(int i=k; i<nums.size(); i++){
            dq.pop_front();
            dq.push_back(nums[i]);
            ans = min(ans, solve(dq));
        }
        return ans;
    }
};