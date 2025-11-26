class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int val1 = 1, val2 = 10, cnt = 2;
        if(val1 % k == 0) return 1;
        for(int i=0; i<6; i++){
            if(val2 >= k) break;
            else{
                val1 = val1 * 10 + 1;
                val2 *= 10;
            }
            cnt++;
        }
        val1 %= k;
        if(val1 == 0) return cnt - 1;
        for(int i=0; i<100; i++){
            val2 %= k;
            val1 = (val1 + val2) % k;
            if(val1 == 0) return cnt;
            val2 *= 10;
            cnt++;
        }
        return -1;
    }
};
/*
k보다 작으면 그대로
k보드 크면 나머지

k = 17

11
100 -> 15
1000 -> 15 * 10 -> 14 + 11
10000 -> 14 * 10 -> 4 + 11
100000 -> 4 * 10 -> 6 + 11
*/