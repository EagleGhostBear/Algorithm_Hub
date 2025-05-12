#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct compare{
    bool operator()(vector<int> left, vector<int> right){
        if(left[2] > right[2]) return true;
        if(left[2] < right[2]) return false;
        
        if(left[1] > right[1]) return true;
        if(left[1] < right[1]) return false;
        
        if(left[0] < right[0]) return true;
        if(left[0] > right[0]) return false;
        
        return false;
    }
};

vector<vector<int>> v; // v[N층][곡갱이 종류]

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    v.resize(minerals.size() / 5 + 1, vector<int>(3, 0));
    for(int i=0; i<minerals.size(); i++){
        int idx = i / 5;
        if(minerals[i] == "diamond"){
            v[idx][0] += 1;
            v[idx][1] += 5;
            v[idx][2] += 25;
        }
        else if(minerals[i] == "iron"){
            v[idx][0] += 1;
            v[idx][1] += 1;
            v[idx][2] += 5;
        }
        else if(minerals[i] == "stone"){
            v[idx][0] += 1;
            v[idx][1] += 1;
            v[idx][2] += 1;
        }
    }
    
    int total = 0;
    for(auto c : picks) total += c;
    if(v.size() > total) v.erase(v.begin() + total, v.end());
    sort(v.begin(), v.end(), compare());
    
    for(int i=0; i<v.size(); i++){
        if(picks[0]) answer += v[i][0], picks[0]--;
        else if(picks[1]) answer += v[i][1], picks[1]--;
        else if(picks[2]) answer += v[i][2], picks[2]--;
    }
    
    // for(int i=0; i<v.size(); i++){
    //     for(int j=0; j<3; j++){
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return answer;
}
/*
종류별로 곡괭이 0 - 5개
*/