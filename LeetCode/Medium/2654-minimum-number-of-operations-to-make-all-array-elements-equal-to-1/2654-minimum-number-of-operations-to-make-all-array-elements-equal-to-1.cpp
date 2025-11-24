class Solution {
public:
    int gcd(int a, int b) {
        while (b) { // 나머지가 0이 될때까지 시행
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int minOperations(vector<int>& nums) {
        int ans = 1, cntOne = 0;
        bool chk = true;
        vector<int> v;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1) cntOne++;
            if(i){
                v.push_back(gcd(nums[i - 1], nums[i]));
                if(v.back() == 1){ chk = false; }
            }
        }
        if(cntOne) return nums.size() - cntOne; // 1이 있으면 바로 종료
        while(v.size() != 1 && chk){
            ans++;
            vector<int> tmp;
            for(int i=1; i<v.size(); i++){
                tmp.push_back(gcd(v[i - 1], v[i]));
                if(tmp.back() == 1){ chk = false; break; }
            }
            v.clear();
            v = tmp;
        }
        if(chk) return -1;
        return ans + nums.size() - 1;
    }
};
/*
가능한 작은 최대공배수를 선택
최대 공배수 1이 없으면 전체를 1로 만들 수 없다?
-> 맞으면서 틀린 이야기, 정확히는 여러번 거쳐야 최대 공배수가 1이 없는지 확인 가능

전략 : 전체 배열에 gcd를 적용시키며 1개를 최대한 빠르게 1로 만드는 횟수를 파악하고 그걸 전파하는 횟수를 더함
*/