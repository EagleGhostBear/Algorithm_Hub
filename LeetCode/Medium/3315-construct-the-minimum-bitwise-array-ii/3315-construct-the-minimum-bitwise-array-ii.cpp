class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 == 0){ans.push_back(-1); continue;}
            int val = 1;
            while((val & nums[i]) == val) val = val * 2 + 1;
            val /= 2;
            // ex) 101111 -> 100111 : 오른쪽 연속된 1을 1자리 줄인게 정답
            // 10000(nums[i] - val) + 111(val / 2)
            if(nums[i] - val) ans.push_back(nums[i] - val + (val / 2));
            else ans.push_back(val / 2); // 2^n - 1 의 형태
        }
        return ans;
    }
};
/*
1. 구조적으로 짝수는 불가
2. 자리수가 바뀔려면 전부 1 인 경우 밖에 없음 -> 1111 || 10000 -> 2^n - 1 의 형태
3. 오른쪽에서 1이 얼마나 이어지는가?
*/