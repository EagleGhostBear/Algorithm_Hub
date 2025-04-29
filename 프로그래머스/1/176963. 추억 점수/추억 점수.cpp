#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> um;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    for(int i=0; i<name.size(); i++) um[name[i]] = yearning[i];
    
    for(int i=0; i<photo.size(); i++){
        int score = 0;
        for(int j=0; j<photo[i].size(); j++) score += um[photo[i][j]];
        answer.push_back(score);
    }
    return answer;
}