class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> preMax(nums.size()); // 각 idx에서 최대값
        preMax[0] = nums[0];
        for(int i=1; i<nums.size(); i++) preMax[i] = max(preMax[i - 1], nums[i]);

        int minVal = 1e9 + 1;
        for(int i=nums.size() - 1; i>-1; i--){
            if(preMax[i] > minVal) ans[i] = ans[i + 1];
            else ans[i] = preMax[i];
            minVal = min(minVal, nums[i]);
        }
        return ans;
    }
};
/*
j < i (nums[j]값이 더 커야만 이동가능)
    i < j (nums[j]값이 더 작아야만 이동가능)

= 최대한 오른쪽으로 뛰고 -> 뒤를 탐색
---
idx가 증가하는 순으로 탐색하므로 지나간 값중에서는 무조건 최대값으로 이동가능
예외사항은 앞쪽으로 이동한뒤 그 뒤에서 최대값을 찾는 경우
*/