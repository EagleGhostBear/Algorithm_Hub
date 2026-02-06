typedef long long ll;

class Solution {
public:
    int binary_search(int startIdx, ll target, vector<int>& nums){
        int left = startIdx, right = nums.size() - 1;
        int mid;
        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] <= target) left = mid + 1;
            else right = mid - 1;
        }
        return mid;
    }
    int minRemoval(vector<int>& nums, int k) {
        int ans = 1e9;
        vector<int> v(nums.size());
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            int idx = binary_search(i, (ll)nums[i] * k, nums);
            if((ll)nums[i] * k < nums[idx]) idx--;
            int cnt = idx - i + 1;
            ans = min(ans, (int)nums.size() - cnt);
        }
        return ans;
    }
};
/*
정렬후 -> 위쪽부터 지울것인가? 아래쪽부터 지울것인가?
*/