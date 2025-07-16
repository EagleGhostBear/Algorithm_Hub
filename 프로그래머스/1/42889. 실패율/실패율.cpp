#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct compare{
    bool operator()(pair<double, int> left, pair<double, int> right){
        if(left.first > right.first) return true;
        if(left.first < right.first) return false;
        
        if(left.second < right.second) return true;
        if(left.second > right.second) return false;
        return false;
    }
};

vector<double> v(502);
vector<int> answer;

vector<int> solution(int N, vector<int> stages) {
    for(int i=0; i<stages.size(); i++) v[stages[i]]++;
    vector<pair<double, int>> tmp;
    int total = stages.size();
    for(int i=1; i<=N; i++){
        tmp.push_back({v[i]/total, i});
        total -= v[i];
    }
    sort(tmp.begin(), tmp.end(), compare());
    for(auto data : tmp) answer.push_back(data.second);
    return answer;
}