class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans = 0, limitP = 2147483647, limitM = -2147483648;
        long long a = abs((long long)dividend), b = abs((long long)divisor), div = b, cnt = 1;
        while(div < a) { div <<= 1; cnt <<= 1;}
        // 둘이 부호가 같을때 +
        if((dividend >= 0 && divisor >= 0) || (dividend < 0 && divisor < 0)){
            while(a >= b){
                if(a >= div){ a -= div; ans += cnt; }
                div >>= 1, cnt >>= 1;
            }
        }
        else{ // 둘이 부호가 다를때 -
            while(a >= b){
                if(a >= div){ a -= div; ans -= cnt; }
                div >>= 1, cnt >>= 1;
            }
        }
        if(ans >= limitP) ans = limitP;
        else if(ans <= limitM) ans = limitM;
        return (int)ans;
    }
};
/*
cs의 기본인 시프트 연산자를 통해 카운트
*/