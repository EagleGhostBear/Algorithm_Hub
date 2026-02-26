class Solution {
public:
    int numSteps(string s) {
        int num = 0, sz = s.size();
        for(int i=0; i<sz; i++){
            if(s[sz - 1 - i] == '1') num += pow(2, i);
        }
        int ans = 0;
        while(num != 1){
            if(num % 2) {num += 1; ans++;}
            num /= 2;
            ans++;
        }
        return ans;
    }
};