#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct compare{
    bool operator()(pair<int, int> left, pair<int, int> right) const {
        if(left.first > right.first) return true;
        if(left.first < right.first) return false;
        
        if(left.second < right.second) return true;
        if(left.second > right.second) return false;
        return false;
    };
};

vector<int> v1 = {1, 2, 3, 4, 5};
vector<int> v2 = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> v3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
vector<pair<int, int>> ans = {{0, 1}, {0, 2}, {0, 3}};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int idx1 = 0, idx2 = 0, idx3 = 0;
    for(int i=0; i<answers.size(); i++){
        if(answers[i] == v1[idx1++]) ans[0].first++;
        if(answers[i] == v2[idx2++]) ans[1].first++;
        if(answers[i] == v3[idx3++]) ans[2].first++;
        if(idx1 == v1.size()) idx1 = 0;
        if(idx2 == v2.size()) idx2 = 0;
        if(idx3 == v3.size()) idx3 = 0;
    }
    sort(ans.begin(), ans.end(), compare());
    int maxv = ans[0].first;
    answer.push_back(ans[0].second);
    for(int i=1; i<3; i++) if(maxv == ans[i].first) answer.push_back(ans[i].second);
    return answer;
}