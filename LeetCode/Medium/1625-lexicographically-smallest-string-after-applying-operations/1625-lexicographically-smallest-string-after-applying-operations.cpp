vector<int> ans;
vector<vector<int>> v;

bool is_chk(vector<int>& tmp, int idx){ // 둘중 더 작을걸 찾는 함수
    for(int i=0; i<ans.size(); i++){
        int nidx = (idx + i) % v.size();
        if(ans[i] > tmp[nidx]){ // 더 작으면 갱신
            for(int j=0; j<v.size(); j++){
                int now = (idx + j) % v.size();
                ans[j] = tmp[now];
            }
            return true;
        }
        else if(ans[i] < tmp[nidx]) break;
    }
    return false;
}

void solve(int odd, int even, int b){ // 홀수idx, 짝수idx 경우의 수에 따른 배열 생성
    vector<int> tmp;
    for(int i=0; i<v.size(); i++){
        if(i%2) tmp.push_back(v[i][odd]);
        else tmp.push_back(v[i][even]);
    }

    int idx = 0;
    is_chk(tmp, idx);
    idx = (idx + b) % v.size();
    while(idx % v.size()){ // 첫 idx = 0 이 다시 0으로 돌아오면 한바퀴 돈것
        is_chk(tmp, idx);
        idx = (idx + b) % v.size();
    }
    return;
}

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        ans.assign(s.size(), 9);
        v.resize(s.size(), vector<int>(10));
        for(int i=0; i<s.size(); i++) v[i][0] = s[i] - '0';
        for(int i=0; i<s.size(); i++) for(int j=1; j<10; j++){
            v[i][j] = (v[i][j-1] + a) % 10;
        }

        if(b % 2){ // 홀수
            // 홀수, 짝수 양쪽다 선택 권한을 가짐 10 * 10 -> 여기서 이동
            for(int i=0; i<10; i++) for(int j=0; j<10; j++) solve(i, j, b);
        }
        else{
            for(int i=0; i<10; i++) solve(i, 0, b);
        }
        
        string answer = "";
        for(auto n : ans) answer += (n + '0');
        return answer;
    }
};
/*
문제는 b=홀수 일때 발생

숫자 바리에이션 = 100자리 숫자가 최대 10가지 바리에이션을 가짐

기본적으로 홀수idx, 짝수idx 끼리 같이 움직임
if(b == 짝수) v[짝수] 값변경 불가, 순서만 조정가능
if(b == 홀수) v[짝수], v[홀수] 둘다 값 변경 가능, 순서도 조정가능
*/