#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> term(26);
vector<pair<int, int>> v;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    int now = stoi(today.substr(0, 4)) * 10000 + stoi(today.substr(5, 2)) * 100 + stoi(today.substr(8, 2));
    for(int i=0; i<terms.size(); i++){
        int type = terms[i][0] - 'A';
        int mon = stoi(terms[i].substr(2));
        term[type] = mon;
    }
    for(int i=0; i<privacies.size(); i++){
        int type = privacies[i][11] - 'A';
        int y = stoi(privacies[i].substr(0, 4));
        int m = stoi(privacies[i].substr(5, 2));
        int d = stoi(privacies[i].substr(8, 2));
        
        y += (term[type] / 12);
        m += (term[type] % 12);
        if(m > 12) y += 1, m -= 12;
        d -= 1;
        if(d == 0){
            m -= 1;
            d = 28;
        }
        int total = y * 10000 + m * 100 + d;
        v.push_back({total, i + 1});
    }
    sort(v.begin(), v.end());
    vector<int> answer;
    for(auto c : v){
        cout << c.first << "," << c.second << "\n";
        if(now > c.first) answer.push_back(c.second);
    }
    sort(answer.begin(), answer.end());
    return answer;
}