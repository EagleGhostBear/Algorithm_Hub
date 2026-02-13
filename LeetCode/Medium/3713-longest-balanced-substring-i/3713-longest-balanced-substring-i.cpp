class Solution {
public:
    int countType(vector<int>& v){
        int ret = 0;
        for(auto n : v) if(n) ret++;
        return ret;
    }
    bool is_balanced(vector<int>& v, int target){
        for(auto n : v) if(n && n != target) return false;
        return true;
    }
    int longestBalanced(string s) {
        int ans = 1;
        vector<vector<int>> prefixSum(s.size(), vector<int>(26, 0));
        for(int i=0; i<s.size(); i++){
            if(i) prefixSum[i] = prefixSum[i - 1];
            prefixSum[i][s[i] - 'a']++;
        }
        for(int right=0; right<s.size(); right++){
            vector<int> tmp = prefixSum[right];
            int cnt = countType(tmp);
            for(int left=0; left<right; left++){
                if(left && --tmp[s[left - 1] - 'a'] == 0) cnt--;
                int len = right - left + 1;
                if(len % cnt) continue;
                if(is_balanced(tmp, len / cnt)) ans = max(ans, len);
            }
        }
        return ans;
    }
};
/*
알파벳 종류 26가지
문제1. 효율적인 범위 선정 방식
문제2. 특정 범위내에 존재하는 알파벳 종류 추출
문제3. 추출해낸 알파벳 종류에서 있는애들만 카운팅 -> 개수가 다 같은지 확인

특징1. 만약 종류수를 알 수 있으면 길이는 종류수 배수로 결정된다.
ex) 알파벳이 범위내 4종류라면 무조건 4, 8, 12, ... 처럼 배수로 증가한다.

특징2. 만약 특정부분을 확인했때, 알파벳 개수의 min, max 값 차이만큼은 움직여야 한다.

해당 위치까지의 종류는 범위의 오른쪽 영역에서 결정된다.
*/