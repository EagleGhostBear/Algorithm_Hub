class Solution {
public:
    int gcd(int a, int b){
        while(b){
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0, sumEven = 0;
        for(int i=1; i<=n + n; i++){
            if(i % 2) sumOdd += i;
            else sumEven += i;
        }
        return gcd(sumOdd, sumEven);
    }
};