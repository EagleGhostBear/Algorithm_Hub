class Solution {
public:
    void convert(int& ret, int val){
        ret *= 4;
        if(val == 1) ret += 2;
        else if(val == 2) ret += 1;
        else if(val == 3) ret += 3;
        return;
    }
    int reverseBits(int n) {
        int ret = 0;
        for(int i=0; i<16; i++){
            convert(ret, n % 4);
            n /= 4;
        }
        return ret;
    }
};