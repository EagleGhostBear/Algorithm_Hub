#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

char max_num = '0';
vector<bool> sys(10); // 몇진법인지
vector<vector<string>> known, unknown;

void split_string(int num, string expression){ // known, unknown 으로 분류
    vector<string> tmp;
    int idx = 0;
    for(int i=0; i<expression.size(); i++) if(expression[i] == ' '){
        tmp.push_back(expression.substr(idx, i - idx));
        idx = i + 1;
    }
    tmp.push_back(expression.substr(idx));
    if(tmp.back() == "X") unknown.push_back(tmp);
    else known.push_back(tmp);
    return;
}

int convert_sys(int val, int sys_idx){ // 10진수로 변환
    int tmp = 0, cnt = 0;
    while(val){
        tmp += (val % 10) * pow(sys_idx, cnt++);
        val /= 10;
    }
    return tmp;
}

string swap_string(string s){
    for(int i=0; i<s.size() / 2; i++){
        char c = s[i];
        s[i] = s[s.size() - 1 - i];
        s[s.size() - 1 - i] = c;
    }
    return s;
}

void chk_sys(){ // 들어오는 숫자보다 작은 애들은 전부 false 처리
    for(int i=0; i<known.size(); i++) for(int j=0; j<known[i].size(); j+=2){
        for(auto c : known[i][j]){
            if(c == 'X' || c <= max_num) continue;
            max_num = c;
        }
        if(max_num == '8') break;
    }
    for(int i=0; i<unknown.size(); i++) for(int j=0; j<unknown[i].size(); j+=2){
        for(auto c : unknown[i][j]){
            if(c == 'X' || c <= max_num) continue;
            max_num = c;
        }
        if(max_num == '8') break;
    }
    for(int i=2; i<=max_num - '0'; i++) sys[i] = false;
    return;
}

bool chk_formula(int idx, int sys_idx, bool sign){ // 연산 결과 일치하지 않는건 false 처리
    int num1 = convert_sys(stoi(known[idx][0]), sys_idx);
    int num2 = convert_sys(stoi(known[idx][2]), sys_idx);
    int num3 = convert_sys(stoi(known[idx][4]), sys_idx);
    // cout << sys_idx << ": " << num1 << " " << num2 << " " << num3 << "\n";
    if(sign){
        if(num1 + num2 != num3) return true;
    }
    else{
        if(num1 - num2 != num3) return true;
    }
    return false;
}

string cal_formula(int idx, int sys_idx, bool sign){ // 해당 진수에 맞게 계산
    string num1 = swap_string(unknown[idx][0]);
    string num2 = swap_string(unknown[idx][2]);
    
    string tmp = "";
    int sz = max(num1.size(), num2.size()) + 1;
    int val = 0; // 올림, 내림에 사용하는 변수
    for(int i=0; i<sz; i++){
        int now = 0;
        if(sign){ // + 계산
            if(i < num1.size()) now += num1[i] - '0';
            if(i < num2.size()) now += num2[i] - '0';
            if(val) now += val--;

            if(now >= sys_idx) now -= sys_idx, val = 1;
            tmp += now + '0';
        }
        else{ // - 계산
            if(i < num1.size()) now += num1[i] - '0';
            if(i < num2.size()) now -= num2[i] - '0';
            if(val) now -= val--;

            if(now < 0) now += sys_idx, val = 1;
            tmp += now + '0';
        }
    }
    string ans = swap_string(tmp);
    // cout << ans << "\n";
    return ans;
}

vector<string> solution(vector<string> expressions) {
    for(int i=2; i<10; i++) sys[i] = true;
    for(int i=0; i<expressions.size(); i++) split_string(i, expressions[i]);
    chk_sys();
    for(int i=0; i<known.size(); i++) for(int j=2; j<sys.size(); j++) if(sys[j]) {
        string sign = known[i][1];
        if(sign == "+") {
            if(chk_formula(i, j, 1)) sys[j] = false;
        }
        else {
            if(chk_formula(i, j, 0)) sys[j] = false;
        }
    }
    // for(auto c : sys) cout << c << " "; cout << "\n";
    
    vector<string> answer;
    int min_sys = 0, max_sys = 0;
    for(int i=2; i<sys.size(); i++) if(sys[i]) {min_sys=i; break;}
    for(int i=sys.size() - 1; i>1; i--) if(sys[i]) {max_sys=i; break;}
    
    for(int i=0; i<unknown.size(); i++) {
        string sign = unknown[i][1];
        string tmp = "";
        for(int j=0; j<4; j++) tmp += unknown[i][j] + " ";
        if(sign == "+") {
            string r1 = cal_formula(i, min_sys, 1);
            string r2 = cal_formula(i, max_sys, 1);
            if(r1 == r2) tmp += to_string(stoi(r1));
            else tmp += '?';
        }
        else {
            string r1 = cal_formula(i, min_sys, 0);
            string r2 = cal_formula(i, max_sys, 0);
            if(r1 == r2) tmp += to_string(stoi(r1));
            else tmp += '?';
        }
        answer.push_back(tmp);
    }
    // for(auto c : answer) cout << c << "\n";
    return answer;
}
/*
2 - 9 진법 계산식을 전부 구현? 비효율

*/