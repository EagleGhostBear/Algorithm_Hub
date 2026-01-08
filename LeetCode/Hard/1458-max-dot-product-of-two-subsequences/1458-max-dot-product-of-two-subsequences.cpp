class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int ans = -1e9;
        // dp[nums1 idx][nums2 idx] = 내적 최대값
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size()));

        for(int idx1=0; idx1<nums1.size(); idx1++){
            for(int idx2=0; idx2<nums2.size(); idx2++){
                // 내적할 경우
                dp[idx1][idx2] = nums1[idx1] * nums2[idx2];
                if((idx1 && idx2) && dp[idx1 - 1][idx2 - 1] > 0) dp[idx1][idx2] += dp[idx1 - 1][idx2 - 1]; // 양수일 경우만 앞쪽에서 가져옴

                // 내적안함
                if(idx1) dp[idx1][idx2] = max(dp[idx1][idx2], dp[idx1 - 1][idx2]);
                if(idx2) dp[idx1][idx2] = max(dp[idx1][idx2], dp[idx1][idx2 - 1]);
                ans = max(ans, dp[idx1][idx2]);
            }
        }
        return ans;
    }
};
/*
dp[nums1 idx][nums2 idx] = 내적 최대값
몇자리인지는 상관없음 어차피 해당 위치에서 값만 크면 된다.
해당 idx 위치에서 내전을 해서 가져갈지 아니면 건너뛸지 선택
*/