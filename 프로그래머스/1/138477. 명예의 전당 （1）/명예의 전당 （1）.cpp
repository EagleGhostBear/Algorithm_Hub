#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> v;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    for(int i=0; i<score.size(); i++){
        if(v.size() < k) v.push_back(score[i]);
        else if(v[0] < score[i]) v[0] = score[i];
        sort(v.begin(), v.end());
        answer.push_back(v[0]);
    }
    return answer;
}