class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        if(nums.size() == 1 || nums[left] < nums[right]){ // 이미 정렬된 상태
            while(left <= right){
                int mid = (left + right) / 2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
            return -1;
        }
        // 회전된 상태
        int rot;
        while(1){
            rot = (left + right) / 2;
            if(nums[left] < nums[rot]) left = rot;
            else if(nums[left] > nums[rot]) right = rot;
            else break;
        }
        left = (nums[0] <= target ? 0 : rot + 1);
        right = (nums[0] <= target ? rot : nums.size() - 1);
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};
/*
log n = 이분탐색
1. 회전구간을 먼저 찾기
2. 회전구간을 기준으로 앞뒤에서 taget이 어느 구간에 해당되는지 찾기
*/