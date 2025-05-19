#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

// 몸무게 범위 : 200 ~ 4000
vector<vector<pair<ll, ll>>> w; // w[균형무게][idx] = {기존무게, 개수}

long long solution(vector<int> weights) {
    long long answer = 0;
    w.resize(4001, vector<pair<ll, ll>>());
    sort(weights.begin(), weights.end());
    pair<int, int> prev = {0, 0};
    for(int i=0; i<weights.size(); i++){
        vector<int> tmp = {2, 3, 4};
        for(int j=0; j<3; j++){
            int now_w = weights[i] * tmp[j];
            if(w[now_w].size() && w[now_w].back().first == weights[i]){
                w[now_w].back().second++;
            }
            else{
                w[now_w].push_back({weights[i], 1});
            }
        }
    }
    for(int i=200; i<4001; i++){
        if(w[i].size()){
            for(int j=0; j<w[i].size(); j++){
                for(int k=j+1; k<w[i].size(); k++){
                    answer += w[i][j].second*w[i][k].second;
                }
                if(w[i][j].second > 1 && i/w[i][j].first == 2){
                    ll n = w[i][j].second;
                    answer += n*(n-1)/2;
                }
            }
        }
    }
    return answer;
}
/*
짝궁 = 양측에 앉았을때 균형이 유지되는 멤버
토크 = 무게 * 좌석거리
*/