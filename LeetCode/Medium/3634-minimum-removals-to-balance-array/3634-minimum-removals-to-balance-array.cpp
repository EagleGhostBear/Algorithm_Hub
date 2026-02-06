class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int ans = 1e9, sz = nums.size();
        sort(nums.begin(), nums.end());
        int right = 0;
        for(int i=0; i<sz; i++){
            for(;right<sz; right++) if((long long)nums[i] * k < nums[right]) break;
            ans = min(ans, sz - right + i);
        }
        return ans;
    }
};
/*
정렬후 -> 위쪽부터 지울것인가? 아래쪽부터 지울것인가?
*/