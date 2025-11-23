class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int ans = 0;
        vector<vector<int>> v(3, vector<int>());
        for(auto n : nums){
            ans += n;
            if(n % 3) v[n % 3].push_back(n);
        }
        if(ans % 3 == 0) return ans;
        sort(v[1].begin(), v[1].end());
        sort(v[2].begin(), v[2].end());

        if(ans % 3 == 1){
            int one = (v[1].size() ? v[1][0] : 1e9);
            int two = (v[2].size() >= 2 ? v[2][0] + v[2][1] : 1e9);
            ans -= min(one, two);
        }
        else{
            int one = (v[1].size() >= 2 ? v[1][0] + v[1][1] : 1e9);
            int two = (v[2].size() ? v[2][0] : 1e9);
            ans -= min(one, two);
        }
        return ans;
    }
};
/*
나머지가 0, 1, 2인것들로 분리
나머지 1, 2로 3을 만들 수 있는 경우의 수
1 2
1 1 1
2 2 2

111
2
이렇게 남았을 경우 3개를 처리하는게 맞는지 1+2 를 처리하는게 더 큰지 생각
---
그냥 다 더한 다음에 만약 % 3 = 0 안된다면 그만큼 빼면 되는거 아닌가?
*/