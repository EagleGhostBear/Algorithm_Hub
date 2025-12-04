typedef long long ll;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int ans = 1e6, rem = 0;
        vector<ll> s(nums.size(), 0); // 전체합
        for(int i=0; i<nums.size(); i++){
            if(i) s[i] = s[i - 1];
            s[i] = (s[i] +nums[i]) % p;
        }
        rem = s[nums.size() - 1] % p;
        if(rem == 0) return 0;
        unordered_map<ll, int> len; // len[%p 나머지] = idx;
        len[0] = -1;

        for(int i=0; i<nums.size(); i++){
            ll target = (s[i] - rem + p) % p;
            if (len.count(target)) ans = min(ans, i - len[target]);
            len[s[i]] = i;
        }
        return (ans > nums.size() - 1 ? -1 : ans);
    }
};
/*
(전체합 - 부분합) % p = 0
s[i] % p = (s[r] - s[l - 1]) % p
우리가 구하고자 하는것 = (s[r] - s[l - 1]) % p 의 길이
필요나머지 = (s[r] - s[l - 1]) % p

// 필요나머지는 어차피 p 보다 낮으므로 내부로 넣고
// +p 는 양수를 보장하기 위해 더해주는데 어차피 % p 로 0이 되므로 결과값에는 영향없다.
(s[l - 1]) % p = (s[r] - 필요나머지 + p) % p
현재 r 에서 필요 나머지를 만들 수 있는 l 의 나머지값, 따라서 값보다는 이때의 
*/