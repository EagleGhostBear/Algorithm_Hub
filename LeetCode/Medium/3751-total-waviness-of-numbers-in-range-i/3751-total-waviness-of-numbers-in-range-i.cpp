class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int n=num1; n<=num2; n++){ // 100,000 * 5
            int tot = 0, quo = n / 10, rem = n % 10, stat = 0;
            while(quo){
                int now = quo % 10;
                if(now < rem && stat > 0) tot++; // 봉우리
                else if(now > rem && stat < 0) tot++; // 골짜기
                stat = now - rem;
                rem = now;
                quo /= 10;
            }
            ans += tot;
        }
        return ans;
    }
};