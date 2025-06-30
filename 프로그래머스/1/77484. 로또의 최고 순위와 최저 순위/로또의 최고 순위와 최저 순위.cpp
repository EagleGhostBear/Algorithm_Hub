#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> score = {6, 6, 5, 4, 3, 2, 1};
unordered_map<int, int> um;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt = 0;
    for(int i=0; i<lottos.size(); i++) um[lottos[i]]++;
    for(int i=0; i<win_nums.size(); i++) if(um[win_nums[i]]) cnt++;
    answer.push_back(score[cnt + um[0]]);
    answer.push_back(score[cnt]);
    return answer;
}