#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> ans = {0, 0};
vector<vector<int>> sale;
vector<vector<int>> global_users;

void solve(vector<int> per){
    vector<int> tmp = {0, 0};
    vector<int> per_tmp = {40, 30, 20, 10};
    vector<int> user(global_users.size(), 0);
    for(int i=0; i<global_users.size(); i++){
        for(int j=0; j<per.size(); j++){
            // 해당 기준 이상의 할인율이면 구매
            if(global_users[i][0] <= per_tmp[per[j]]) user[i] += sale[per[j]][j];
        }
        if(user[i] >= global_users[i][1]) tmp[0]++;
        else tmp[1] += user[i];
    }
    if(tmp[0] > ans[0] || (tmp[0] == ans[0] && tmp[1] > ans[1])){
        ans = tmp;
        // for(auto c : per) cout << per_tmp[c] << " ";
        // cout << tmp[0] << "," << tmp[1];
        // cout << "\n-------------\n";
    }
    return;
}

void sel(vector<int> per){ // 4^7 = 16,384 // 모든 할인율 고려 
    if(per.size() == sale[0].size()){
        solve(per);
        return;
    }
    
    for(int j=0; j<4; j++){
        per.push_back(j);
        sel(per); // 다음 이모티콘
        per.pop_back();
    }
    return;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    global_users = users;
    sale.resize(4, vector<int>(emoticons.size()));
    sort(emoticons.begin(), emoticons.end());
    for(int i=0; i<4; i++){
        vector<int> tmp = {40, 30, 20, 10};
        for(int j=0; j<emoticons.size(); j++){
            sale[i][j] = emoticons[j] * (100 - tmp[i]) / 100;
        }
    }
    sel({});
    return ans;
}
/*
1. 구독제 상품 가입자 수
2. 판매액
*/