class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> dp(sz, vector<int>(sz));
        for(int i=0; i<sz; i++) dp[i][i] = nums[i]; // len = 1 일때 만들 수 있는 최대값
        for(int len=2; len<=sz; len++){ // 배열의 길이가 len 일때 뽑을 수 있는 최대값
            for(int l=0; l + len - 1 < sz; l++){
                int r = l + len - 1;
                // nums[l]을 뽑았으면 상대편은 l+1 ~ r 까지의 배열에서 최선의 값을 뽑아야함
                // nums[r]을 뽑았으면 상대편은 l ~ r-1 까지의 배열에서 최선의 값을 뽑아야함
                dp[l][r] = max(nums[l] - dp[l + 1][r], nums[r] - dp[l][r - 1]);
            }
        }
        if(dp[0][sz - 1] >= 0) return true;
        return false;
    }
};
/*
dp 게임이론 문제(역방향 접근)
*/