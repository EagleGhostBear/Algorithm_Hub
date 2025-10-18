vector<int> v;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        v.assign(value, 0);
        for(int i=0; i<nums.size(); i++){
            int tmp = nums[i] % value;
            if(tmp >= 0) v[tmp]++;
            else v[tmp + value]++;
        }
        pair<int, int> ans = {2e9, -1}; // 최소개수, idx
        for(int i=0; i<v.size(); i++){
            if(ans.first > v[i]) {ans.first = v[i]; ans.second = i;};
        }
        return ans.second + (ans.first * value);
    }
};
/*
음수 -> 무조건 0 이상으로 전환시켜야함
같은 숫자가 가능한것 -> 묶어야함
value = 5
[0, 1, 2, 3, 4] -> 해당 범위가 몇 세트 나오냐에 따라 어디까지 갈 수 있는 확인 가능
[8, 5, 3, 7, 6] -> 각 원소의 개수가 이렇다고 가정하면 -> 2 + (minv * 5) = 17
*/