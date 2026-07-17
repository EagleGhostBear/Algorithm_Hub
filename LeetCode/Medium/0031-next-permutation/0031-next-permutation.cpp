class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return;
        bool is_chk = true;
        for(int i=nums.size() - 2; i>-1; i--){
            if(nums[i] < nums[i + 1]){ // 정순이면 값이 편하는 수
                is_chk = false;
                int idx = i + 1, val = nums[i + 1];
                for(int j=i+1; j<nums.size(); j++){
                    if(nums[i] < nums[j] && nums[j] < val) {idx = j; val = nums[j];}
                }
                int tmp = nums[i];
                nums[i] = val;
                nums[idx] = tmp;
                sort(nums.begin() + i + 1, nums.end());
                break;
            }
        }
        if(is_chk) sort(nums.begin(), nums.end());
        return;
    }
};