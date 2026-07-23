class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = 1, sz = nums.size();
        if(sz == 1) return 1;
        else if(sz == 2) return 2;
        while(sz >= n) n <<= 1;
        n--;
        if(sz > 2) n++; // 0만들기 가능
        return n;
    }
};
/*
XOR(^) 연산의 수학적 의미를 이해해야함
*/