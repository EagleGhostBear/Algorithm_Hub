#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> v(2, vector<int>(10, 0));

string solution(string X, string Y) {
    for(auto c : X) v[0][c - '0']++;
    for(auto c : Y) v[1][c - '0']++;
    string answer = "";
    for(int i=9; i>-1; i--){
        int minv = min(v[0][i], v[1][i]);
        for(int j=0; j<minv; j++) answer += char(i + '0');
    }
    if(answer == "") return "-1";
    for(int i=0; i<answer.size(); i++){
        if(answer[i] != '0') return answer.substr(i);
    }
    return "0";
}