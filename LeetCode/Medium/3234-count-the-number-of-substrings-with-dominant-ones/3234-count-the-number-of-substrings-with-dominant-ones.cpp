class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        vector<int> zeros, ones;
        int oneCnt = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0'){
                zeros.push_back(i);
                if(oneCnt) ones.push_back(oneCnt);
                oneCnt = 0;
            }
            else oneCnt++;
        }
        if(oneCnt) ones.push_back(oneCnt);

        // 0이 없는 상황 계산
        for(int i=0; i<ones.size(); i++){
            ans += (ones[i] * (ones[i] + 1)) / 2;
        }

        // 0의 개수에 따라 계산
        int maxSz = min(int(zeros.size()), int(sqrt(s.size())));
        for(int cnt=1; cnt<=maxSz; cnt++){ // 0의 개수
            // L, R 범위 설정 후 투포인터로 이동
            int minOne = pow(cnt, 2); // 필요한 최소 1의 개수
            for(int idxL=0; idxL<zeros.size() - cnt + 1; idxL++){
                int idxR = idxL + cnt - 1;
                int minL = 0, maxR = s.size(); // L, R 시작 범위
                if(idxL > 0) minL = zeros[idxL - 1] + 1;
                if(idxR < zeros.size() - 1) maxR = zeros[idxR + 1];

                int minR = -1;
                for(int l=minL; l<=zeros[idxL]; l++){
                    bool chk = true;
                    for(int r=max(minR, zeros[idxR]); r<maxR; r++){
                        int one = r - l + 1 - cnt; // 범위내 1의 개수
                        if(minOne <= one){
                            if(chk){minR=r; chk=false;}
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
/*
a >= b^2
0 <= b <= 2 * 100

cnt0 <= sqrt(len + 1/4) - 1/2
*/