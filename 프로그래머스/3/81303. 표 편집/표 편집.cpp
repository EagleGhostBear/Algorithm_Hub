#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct node{ int idx, pv, nt; };

int idx;
vector<int> pv;
vector<int> nt;
stack<node> s; // idx - 삭제된 인덱스 기억

void up(){
    idx = pv[idx];
    return;
}

void down(){
    idx = nt[idx];
    return;
}

void del(){
    s.push({idx, pv[idx], nt[idx]});
    if(pv[idx] != -1) nt[pv[idx]] = nt[idx];
    if(nt[idx] != -1) pv[nt[idx]] = pv[idx];
    
    if(nt[idx] != -1) idx = nt[idx]; // 기본적으로는 아래로 이동
    else idx = pv[idx]; // 아래로 이동이 불가하면 이전으로 이동
    return;
}

void restore(){
    node now = s.top();
    s.pop();
    
    if(now.pv != -1) nt[now.pv] = now.idx;
    if(now.nt != -1) pv[now.nt] = now.idx;
    return;
}

string solution(int n, int k, vector<string> cmd) {
    string ans = "";
    for(int i=0; i<n; i++){
        pv.push_back(i - 1);
        nt.push_back(i + 1);
    }
    nt[n - 1] = -1;
    idx = k;
    for(int i=0; i<cmd.size(); i++){
        char order = cmd[i][0];
        int num;
        if(order != 'C' && order != 'Z') num = stoi(cmd[i].substr(2));
        
        if(order == 'U') while(num--) up();
        else if(order == 'D') while(num--) down();
        else if(order == 'C') del();
        else if(order == 'Z' && s.size()) restore();
    }
    while(pv[idx] != -1) idx = pv[idx];
    while(nt[idx] != -1){
        while(ans.size() < idx) ans += 'X';
        ans += 'O';
        idx = nt[idx];
    }
    while(ans.size() < idx) ans += 'X';
    ans += 'O';
    while(ans.size() < n) ans += 'X';
    return ans;
}
/*
dq.insert() 해당 인덱스 앞에 삽입
dq.erase() 해당 인덱스 위치 삭제
*/