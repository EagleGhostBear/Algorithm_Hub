class Solution {
public:
    bool hasAlternatingBits(int n) {
        int mod = -1;
        while(n){
            if(n % 2 == mod) return false;
            else mod = n % 2;
            n /= 2;
        }
        return true;
    }
};