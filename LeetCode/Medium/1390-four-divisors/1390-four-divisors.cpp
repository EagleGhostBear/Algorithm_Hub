class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        vector<int> val(1e5 + 1, -1);
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(val[nums[i]] >= 0) {ans += val[nums[i]]; continue;}
            int cntDivi = 2, sumDivi = 1 + nums[i], limit = sqrt(nums[i]);
            for(int div=2; div<=limit; div++){
                if(nums[i] % div == 0){
                    int quo = nums[i] / div;
                    if(div != quo) cntDivi++, sumDivi += quo;
                    cntDivi++, sumDivi += div;
                }
                if(cntDivi > 4) break;
            }
            if(cntDivi == 4) ans += sumDivi, val[nums[i]] = sumDivi;
            else val[nums[i]] = 0;
        }
        return ans;
    }
};
/*
약수의 대칭성을 이용해 sqrt(nums[i]) 까지만 탐색
*/