#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
int global_n;
vector<int> global_ans;
vector<vector<int>> test;

bool is_test(vector<int> v){
    for(int i=0; i<test.size(); i++){
        int cnt = 0;
        for(int j=0; j<v.size(); j++){
            if(test[i][v[j]]) cnt++;
        }
        if(global_ans[i] != cnt) return false;
    }
    return true;
}

void solve(vector<int> v){
    if(v.size() == 5){
        if(is_test(v)) answer++;
        return;
    }
    else{
        for(int i = v.back() + 1; i<=global_n; i++){
            v.push_back(i);
            solve(v);
            v.pop_back();
        }
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    global_n = n;
    global_ans = ans;
    test.resize(q.size(), vector<int>(n + 1, 0));
    for(int i=0; i<q.size(); i++){
        for(int j=0; j<q[i].size(); j++) test[i][q[i][j]]++;
    }
    
    for(int i=1; i<=n; i++){
        solve({i});
    }
    
    return answer;
}